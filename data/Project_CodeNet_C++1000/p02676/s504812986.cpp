#include <stdio.h>
#include <string.h>

int main(){
	int A;
	char kataA[101];
	
	scanf("%d", &A);
	scanf("%s", kataA);
	
	int longKata=strlen(kataA);
	
	if(longKata>A){
		kataA[A]='\0';
		for(int i=0; kataA[i]!='\0'; i++){
				printf("%c", kataA[i]);
		}
		puts("...");
	}else{
		printf("%s", kataA);
	}
	
	return 0;
}