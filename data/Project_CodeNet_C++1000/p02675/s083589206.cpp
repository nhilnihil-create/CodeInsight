#include <stdio.h>

int main() {
	
	int angka = 0;
	scanf("%d",&angka);
	angka %= 10;
	if(angka == 2 || angka == 4 || angka == 5 || angka == 7 || angka == 9){
		printf("hon\n");
	}else if(angka == 0 || angka == 1 || angka == 6 || angka == 8){
		printf("pon\n");
	}else if(angka == 3){
		printf("bon\n");
	}
	return 0;
}