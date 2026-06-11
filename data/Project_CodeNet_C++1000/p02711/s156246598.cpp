#include <stdio.h>

int main (){
	int angka, ratusan, puluhan, satuan;
	
	scanf("%d", &angka);
	ratusan = (angka / 100);
	puluhan = (angka%100)/10;
	satuan = (angka%100%10);
	
	if(ratusan == 7 || puluhan== 7||satuan ==7){
		puts("Yes");
	}
	else {
		puts("No");
	}
	return 0;
}