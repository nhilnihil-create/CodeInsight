#include<stdio.h>
#include <string.h>
int main(){
	char kata[101];
	int angka;
	scanf("%d", &angka);
	scanf("%s", &kata);
	int panjangKata = strlen(kata);
	
	
	if(panjangKata>angka){
		kata[angka] = '\0';
		for(int i=0; kata[i] != '\0'; i++){
			printf("%c", kata[i]);
		}
		printf("...");
	}
	
	else {
		printf("%s", kata);
	}
	

	return 0 ;
}