#include<stdio.h>
#include<string.h>
int main(){
	char nama[5];
	
	scanf("%s", nama);
	
	if(strcmp(nama, "ABC") == 0){
		printf("ARC");
	} else if (strcmp(nama, "ARC") == 0){
		printf("ABC");
	} else {
	}
	
	return 0;
}