#include <stdio.h>

int main(){
	
	int bawah, atas, angka;
	scanf("%d %d %d", &bawah, &atas, &angka);
	int hasil =0;
		for(int j = 1; j <= atas; j++){
			if(angka * j >= bawah && angka * j <= atas){
				hasil++;
			}
		}
	printf("%d\n", hasil);
	
	return 0;
}