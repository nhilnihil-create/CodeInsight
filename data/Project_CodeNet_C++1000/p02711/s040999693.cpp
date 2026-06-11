#include<stdio.h>
int main(){
	int angka, digitBelakang, digitTengah, digitAwal;
	scanf("%d", &angka);
	
	digitBelakang = angka % 10;
	
    digitTengah = (angka - digitBelakang) / 10 % 10;
   	
    digitAwal = (angka - digitBelakang) / 100 % 10 ;
	
	if (digitBelakang == 7){
		puts ("Yes");
	}
	else if (digitTengah == 7){
		puts ("Yes");
	}
	else if (digitAwal == 7){
		puts ("Yes");
	}
	else {
		puts ("No");
	}
	return 0;
}