#include <stdio.h>

int main(){
	int angka;
	scanf ("%d", &angka);
	
	bool cekAngka = false;
	for (int i = 1 ; i<=9; i++){
		for (int j = 1; j <=9; j++){
			if (angka == (i*j)){
				cekAngka = true;
				break;
			}
		}
	}
	
	if (cekAngka){
		puts("Yes");
	}
	else {
		puts ("No");
	}
	return 0;
}