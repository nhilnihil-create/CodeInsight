#include<stdio.h>
#include<string.h>

int main(){
	char A1[15],B1[15],C1[15];
	int bola1,bola2;
	scanf("%s %s",A1,B1);
	scanf("%d %d",&bola1,&bola2);
	scanf("%s",C1);
	
	(strcmp(C1,A1)==0) ? bola1-- : bola2--;
	printf("%d %d\n",bola1,bola2);
	
	return 0;
	
}
	