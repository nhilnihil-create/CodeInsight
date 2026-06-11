#include <stdio.h>

int main(){
	
	int angka;
	scanf("%d", &angka);
	
	int angka3 = angka % 10;
 
	int angka2 = (angka - angka3) / 10;
	int angka2real = angka2 % 10;
	int angka1 = angka - (angka2real * 10) - angka3;
	int angka1real = angka1 / 100;
	
	if(angka1real == 7){
		printf("Yes\n");
	}
	else if(angka2real == 7){
		printf("Yes\n");
	}
	else if(angka3 == 7){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}