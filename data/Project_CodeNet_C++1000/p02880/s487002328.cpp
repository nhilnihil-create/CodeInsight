#include <stdio.h>

int main(){
	int angka;
	scanf("%d", &angka);
	int count = 0;
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			if(angka == i * j){
				count++;
			}
		}
	}
	if(count != 0){
		puts("Yes");
	} else{
		puts("No");
	}
	return 0;
}