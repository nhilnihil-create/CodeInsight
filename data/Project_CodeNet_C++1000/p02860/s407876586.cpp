#include <stdio.h>

int main (){
	int angka;
	scanf("%d", &angka);
	
	char kata[angka+1];
	scanf("%s", kata);
	
	if(angka % 2 != 0){
		puts("No");
	}
	
	else {
		int tanda = 1;
		for (int i =0; i < angka/2; i++){
			if (kata[i] != kata[i+ angka/2]){
				tanda = 0;
			}
		}
		
		if (tanda == 1){
			puts("Yes");
		}
		else {
			puts("No");
		}
	}
	return 0;
}