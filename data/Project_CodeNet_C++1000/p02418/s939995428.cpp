#include<stdio.h>
#include<string.h>
int main(void){
	char rareru[101],rareru2[101];
	char ru[101];
	scanf("%100s",rareru);
	scanf("%100s",ru);
	strcpy(rareru2,rareru);
	strcat(rareru,rareru2);
	if(strstr(rareru,ru)!=NULL){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}