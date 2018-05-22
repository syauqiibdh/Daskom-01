#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char bus[5][130]= {"PO Fathul Muin","PO Agra Mas","PO Andaria","PO Artha Jaya","PO Arya Prima"};
char nama_penumpang[32][100]= {'\0'};
int harga_tiket = 20000;
int nomor_bangku[32]= {0};
int nomor_bus = 0;
void login();
void lihat_daftar_bus();
void list_bus();//nama-nama bus
void catat_booking(int jumlah_bangku_dibooking, char numstr[100]);
void booking();//untuk booking tiket
int salin_nomor_bangku(int nomor_bus);//untk membaca angka dari data
void salin_nama_penumpang(int nomor_bus);//untuk membaca nama dari data
void status();//untuk mengeprint status dari pemesan
void print_status_bus(int nomor_bus);//untuk mengeprint status ketika memesan tiket

int main() {
	
	char menu;
	do{
        fflush(stdin);
        system("cls");
		printf("\n\n\n\n\t============= SELAMAT DATANG DI SISTEM RESERVASI BUS =============\n\n\n");
		printf("\t\t[1] Lanjut ke Sistem Reservasi Tiket BUS\n\n");
		printf("\t\t[2] Bantuan\n\n");
		printf("\t\t[3] Keluar\n\n\n");
		printf("\t\tpilihan anda---->");
		scanf("%s", &menu);
		
		switch (menu) {
	    case '1':
	        // panggil fungsi login
	   		login();
	   		char num;
	   		
	   		x:
	   		
        	fflush(stdin);
            system("cls");
            printf("\n\n\n");
            printf("\t============= SELAMAT DATANG DI SISTEM RESERVASI BUS =============\n\n\n");
            printf("\t\t[1]=> Lihat Daftar Bus\n");
            printf("\n");
            printf("\t\t[2]=> Pesan Tiket\n");
            printf("\n");
            printf("\t\t[3]=> Status Tempat duduk bus\n");
            printf("\n");
            printf("\t\t[4]=> Keluar\n\n");
            printf("\t\t=====================================================\n\n");
            printf("\t\t\tPilihan Anda: ");
            scanf("%s", &num);
        
    		switch (num) {
	   		case '1':
	      	lihat_daftar_bus();
	      	goto x;
	      	break;
	    	case '2':
	      	booking(); //untuk booking ticket
	      	goto x;
	      	break;
	    	case '3':
	      	status();
	      	goto x;
	      	break;
	      	case '4':
	      	system("cls");
		    printf("--------------------------------------------------------------------------------\n");
		    printf("\t\t\tTerima kasih telah menggunakan sistem ini\t\t\t\n");
		    printf("--------------------------------------------------------------------------------\n");
		    getch();
		    break;
	    	default:
	    	system("cls");
	      	printf("\n\n\n\n\n\n\n\n\n--------------------------------------------------------------------------------\n");
		    printf("\t\tError! Pilih opsi yang tertera pada program!\t\t\t\n\t\tTekan apa saja untuk kembali ke menu awal.\n");
		    printf("--------------------------------------------------------------------------------\n");
	      	getch();
	      	goto x;
    		}
    
		    // kalau pilihan adalah 4
		    
		    
		    return 0;
	   		 break;
	   		 
	   	case '2':
	    	// Memanggil menu Help 
	    	system("cls");
	    	printf("\n\n\t============= SELAMAT DATANG DI SISTEM RESERVASI BUS =============\n\n");
	    	printf("\n\n\n\tProgram ini digunakan untuk mereservasi tiket bus\n\n\n");
	    	printf("\t1. Login terlebih dahulu untuk memasuki halaman utama reservasi bus\n\n");
	    	printf("\t2. Pilih apa yang ingin anda lakukan sesuai dengan pilihan yang ada");
	    	printf("\n\n\n\n\t==================================================================\n\n");
	    	printf("\n\n\n\n\t\tTekan apa saja untuk melanjutkan ke awal.");
	    	getch();
	    	//login();
	    	break;
	    	
	    case '3':
	    	system("cls");
		    printf("--------------------------------------------------------------------------------\n");
		    printf("\t\tTerima kasih telah menggunakan sistem ini\t\t\t\n");
		    printf("--------------------------------------------------------------------------------\n");
		    getch();
		    
            return 0; 
            break;
            
	    default:
	    	system("cls");
	    	printf("\n\n\n\n\n\n\n\n\n--------------------------------------------------------------------------------\n");
		    printf("\t\tError! Pilih opsi yang tertera pada program!\t\t\t\n\t\tTekan apa saja untuk kembali ke menu awal.\n");
		    printf("--------------------------------------------------------------------------------\n");
	    	getch();
	    	break;
		}
		
		}while (menu != '1' || menu != '2' || menu != '3');
		
	
return 0;
}
    
 

void lihat_daftar_bus() {
	list_bus();
    printf("\n\n\n\t\t\t\tPencet apa saja untuk melanjutkan...");
    getch();
}

void list_bus() {
    system("cls");
    printf("\n\n\n");
    printf("============================= SISTEM RESERVASI BUS =============================\n\n\n");
    printf("\t\t\t[1]  =>  %s\n",bus[0]);
    printf("\n");
    printf("\t\t\t[2]  =>  %s\n",bus[1]);
    printf("\n");
    printf("\t\t\t[3]  =>  %s\n",bus[2]);
    printf("\n");
    printf("\t\t\t[4]  =>  %s\n",bus[3]);
    printf("\n");
    printf("\t\t\t[5]  =>  %s\n",bus[4]);
}

void ask_bus_header() {
	int cek_karakter;
	do {
		cek_karakter = 0;
		fflush(stdin);
		system("cls");
	    printf("================================ SISTEM RESERVASI BUS ================================\n\n\n");
		// print list bus yang ada
		list_bus();
		// terima input jenis bus yang dipilih
		printf("Masukkan nomor bus:--->");
		cek_karakter = scanf("%d", &nomor_bus);	
	} while (nomor_bus < 1 || nomor_bus > 5 || cek_karakter != 1);
}

void booking() {
	char nomor_bus_string[10];
	ask_bus_header();
	print_status_bus(nomor_bus);
    
	FILE *file_ketersediaan_bangku, *fopen(); //Untuk membaca bngku dari file.
    char ketersediaan_bangku_string[80] = "32";
    int jumlah_bangku_tersedia, jumlah_bangku_dibooking = 0;
    // baca ketersediaan bangku sesuai dengan bus yang dipilih
	if (nomor_bus == 1) {
        file_ketersediaan_bangku = fopen("tr1.txt", "r+");
        fgets(ketersediaan_bangku_string, 80, file_ketersediaan_bangku);
        fclose(file_ketersediaan_bangku);
    } else if(nomor_bus == 2) {
        file_ketersediaan_bangku = fopen("tr2.txt", "r+");
        fgets(ketersediaan_bangku_string, 80, file_ketersediaan_bangku);
        fclose(file_ketersediaan_bangku);
    } else if(nomor_bus == 3) {
        file_ketersediaan_bangku = fopen("tr3.txt", "r+");
        fgets(ketersediaan_bangku_string, 80, file_ketersediaan_bangku);
        fclose(file_ketersediaan_bangku);
    } else if(nomor_bus == 4) {
        file_ketersediaan_bangku = fopen("tr4.txt", "r+");
        fgets(ketersediaan_bangku_string, 80, file_ketersediaan_bangku);
        fclose(file_ketersediaan_bangku);
    } else if(nomor_bus == 5) {
        file_ketersediaan_bangku = fopen("tr5.txt", "r+");
        fgets(ketersediaan_bangku_string, 80, file_ketersediaan_bangku);
        fclose(file_ketersediaan_bangku);
    }
    
	jumlah_bangku_tersedia = atoi(ketersediaan_bangku_string); //mengganti string menjadi angka
    
	if (jumlah_bangku_tersedia <= 0) {
        printf("Tidak ada bangku kosong disini ");
    } else {
        printf("\n\n\n\t\t\t\tBangku yang tersedia:------>%d\n", jumlah_bangku_tersedia);
        printf("\n\t\t\t\tJumlah tiket yang ingin dibeli:----->");
        scanf("%d", &jumlah_bangku_dibooking);
        printf("\n");

        jumlah_bangku_tersedia = jumlah_bangku_tersedia - jumlah_bangku_dibooking;
        // ubah nomor bus dari integer menjadi string
		itoa(nomor_bus, nomor_bus_string, 10);
        catat_booking(jumlah_bangku_dibooking, nomor_bus_string);
        printf("\n\t\t\t\tTotal harga pesanan adalah Rp %d", harga_tiket * jumlah_bangku_dibooking);
        // ubah jumlah bangku tersedia dari integer menjadi string
		itoa(jumlah_bangku_tersedia, ketersediaan_bangku_string, 10);
        
		// tuliskan kembali nilai terbaru bangku tersedia pada file
		if(nomor_bus == 1) {
            file_ketersediaan_bangku = fopen("tr1.txt","w");
            fputs(ketersediaan_bangku_string,file_ketersediaan_bangku);
            fclose(file_ketersediaan_bangku);
        } else if(nomor_bus == 2) {
            file_ketersediaan_bangku = fopen("tr2.txt","w");
            fputs(ketersediaan_bangku_string,file_ketersediaan_bangku);
            fclose(file_ketersediaan_bangku);
        } else if(nomor_bus == 3) {
            file_ketersediaan_bangku = fopen("tr3.txt","w");
            fputs(ketersediaan_bangku_string,file_ketersediaan_bangku);
            fclose(file_ketersediaan_bangku);
        } else if(nomor_bus == 4) {
            file_ketersediaan_bangku = fopen("tr4.txt","w");
            fputs(ketersediaan_bangku_string,file_ketersediaan_bangku);
            fclose(file_ketersediaan_bangku);
        } else if(nomor_bus == 5) {
            file_ketersediaan_bangku = fopen("tr5.txt","w");
            fputs(ketersediaan_bangku_string,file_ketersediaan_bangku);
            fclose(file_ketersediaan_bangku);
        }
    }
    getch();
}

void catat_booking(int jumlah_bangku_dibooking, char nomor_bus_string[100]) {
    char nomor_string[100], status_string[12] = "status", number_string[12] = "number";
    int nomor_bangku_dipilih, i;
    FILE *file_status_bangku_booking, *file_status_nama_booking;
    
	strcat(nomor_bus_string, ".txt");
    strcat(status_string, nomor_bus_string);
    strcat(number_string, nomor_bus_string);
    file_status_bangku_booking = fopen(status_string, "a");//untuk membuka data serta menulis nama di data
    file_status_nama_booking = fopen(number_string, "a");//untuk membuka data serta menulis angka di data
    
	//untuk memasukan nama orang dan nomor bangku di data
	for(i = 0; i < jumlah_bangku_dibooking; i++) {
        printf("==========================Masukkan detail pelanggan %d==========================\n\n\n", i + 1);
        printf("\t\t\t\tMasukkan nomor bangku:--->");
        scanf("%d", &nomor_bangku_dipilih);
        printf("\t\t\t\tMasukkan nama pelanggan:--->");
        scanf("%s", nama_penumpang[nomor_bangku_dipilih - 1]);
        printf("\n===============================================================================\n\n");
        printf("\n");
        
        // mengganti integer jadi string
		itoa(nomor_bangku_dipilih, nomor_string, 10);
        fprintf(file_status_bangku_booking, "%s ", nama_penumpang[nomor_bangku_dipilih - 1]);
        fprintf(file_status_nama_booking, "%s ", nomor_string);
    }
    fclose(file_status_bangku_booking);
    fclose(file_status_nama_booking);
}

int salin_nomor_bangku(int nomor_bus) {
    char nomor_bus_string[100];
	char nomor_string[32][2] = {'\0'};
	char file_name[12] = "number";
    FILE *file_nomor_bangku;
    int i = 0, j = 0, jumlah_terisi;
    // ubah nomor bus agar dapat membaca file terkait
    itoa(nomor_bus, nomor_bus_string, 10);
    strcat(nomor_bus_string, ".txt");
    strcat(file_name, nomor_bus_string);
    
    // membuka file di komputer
    file_nomor_bangku = fopen(file_name, "a+");
    // baca seluruh file nomor bangku bus
	while(!feof(file_nomor_bangku)) {
        nomor_string[i][j] = fgetc(file_nomor_bangku);
        if (nomor_string[i][j] == ' ') {
            j = 0;
            i++;
        } else {
            j++;
        }
    }
    jumlah_terisi = i;
    for (i = 0; i < jumlah_terisi; i++) {
    	// salin nomor bangku terisi
        nomor_bangku[i] = atoi(nomor_string[i]);
    }
    
	fclose(file_nomor_bangku);
    return jumlah_terisi;
}

void salin_nama_penumpang(int nomor_bus) {
    char nomor_bus_string[100];
	char file_name[12] = "status";
    FILE *file_nama_penumpang;
    int i = 0, j = 0;
    // ubah nomor bus agar dapat membaca file terkait
    itoa(nomor_bus, nomor_bus_string, 10);
    strcat(nomor_bus_string, ".txt");
    strcat(file_name, nomor_bus_string);
    file_nama_penumpang = fopen(file_name, "a+");
    // baca seluruh file nomor bangku bus
	while(!feof(file_nama_penumpang))
    {
        nama_penumpang[i][j] = fgetc(file_nama_penumpang);
        if(nama_penumpang[i][j] == ' ') {
            j = 0;
            i++;
        } else {
            j++;
        }
    }
    
    nama_penumpang[i][j] = '\0';
    fclose(file_nama_penumpang);
}

void status() {
    ask_bus_header();
	print_status_bus(nomor_bus);
	printf("\n\n\n\t\t\t\tPencet apa saja untuk melanjutkan...");
	getch();
}

void print_status_bus(int nomor_bus) {
    system("cls");
	printf("________________________________________________________________________________\n");
    printf("                       Bus No.%d - %s                        \n", nomor_bus, bus[nomor_bus - 1]);
    printf("________________________________________________________________________________\n");
    
	int i, j, index = 0, jumlah_bangku_terisi;
    jumlah_bangku_terisi = salin_nomor_bangku(nomor_bus);
    salin_nama_penumpang(nomor_bus);
    
	char nama_penumpang_sekarang[33][10]= {"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    // salin nama penumpang ke nama penumpang sekarang
	for(i = 0; i < jumlah_bangku_terisi; i++) {
        strcpy(nama_penumpang_sekarang[nomor_bangku[i]], nama_penumpang[i]);
    }
    // cetak nama penumpang sekarang
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 4; j++) {
            printf("%d.%s\t", index + 1, nama_penumpang_sekarang[index + 1]);
            index++;
        }
        printf("\n");
    }
}



void login() {
    int count_login = 0;
    char user_name[10], c = ' ';
    char password[10];
    char user[10] = "user";
    char pass[10] = "pass";
    do {
        system("cls");

        printf("\n\n  =========================  LOGIN  =========================  ");
        printf("\n\n\n                       Masukkan USERNAME:-");
        scanf("%s", &user_name);
        printf("\n                       Masukkan PASSWORD:-");
        // ubah setiap ketikan password menjadi *
        // panjang password boleh diketik adalah 10
        int count_password = 0;
		while (count_password < 10) {
            fflush(stdin);
            password[count_password] = getch();
            c = password[count_password];
            if (c == 13) break;
            if (c == 8) printf("");
            else printf("*");
            count_password++;
        }
        // tambahkan escape character agar menjadi string
        password[count_password] = '\0';
        // bandingkan user_name dan password, pastikan bernilai sama
		if ((strcmp(user_name, user) == 0) && (strcmp(password, pass) == 0)) {
            printf("  \n\n\n       SELAMAT DATANG DI SISTEM KAMI !!!! LOGIN BERHASIL");
            printf("\n\n\n\t\t\t\tPencet apa saja untuk melanjutkan...");
            getch();
            break;
        } else {
            printf("\n        MAAF !!!!  LOGIN TIDAK BERHASIL");
            count_login++;
           getch();//holds the screen

        }
    } while (count_login <= 2); // pastikan jumlah boleh login hanya 3 kalo percobaan
    
	if (count_login > 2) {
        printf("\nMohon maaf anda salah memasukkan username dan password hingga 3 kali!!!");
        printf("\nAnda akan keluar dari sistem!!!");
        getch();
		// pastikan program keluar karena gagal login
		exit(0);
    }
    system("cls");
	}
