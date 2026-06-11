#include<stdio.h>
#include<string.h>
int main(){
	
	char S[15];
	char T[15];
	char U[15];
	
	int A;
	int B;
	
	scanf("%s %s",S,T);
	
	scanf("%d %d",&A,&B);
	
	scanf("%s",U);
	
	
	if(strcmp(U,S)==0){
		printf("%d %d\n",A-1,B);
	}
	else if(strcmp(U,T)==0){
		printf("%d %d\n",A,B-1);
	}
	
	return 0;
	
	
	
	
	
	
	
}