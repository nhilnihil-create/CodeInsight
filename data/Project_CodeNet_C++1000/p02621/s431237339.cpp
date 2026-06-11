#include <stdio.h>

int main (){
	int angka;
	scanf("%d", &angka);
	int jumlah=0;
	jumlah = (angka) + (angka*angka) + (angka*angka*angka);
	printf("%d", jumlah);
	
	return 0 ;
}