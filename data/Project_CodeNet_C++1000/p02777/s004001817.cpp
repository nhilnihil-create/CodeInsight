#include<stdio.h>
#include<string.h>
	int main(){
	int A,B;
	char S[15],T[15],U[15];
	
	scanf("%s %s",&S,&T);
	scanf("%d %d",&A,&B);
	getchar();
	scanf("%s",&U);
	
	if( strcmp(S,U)==0){
		A--;
		
	}
	else {
		B--;
	}		
		printf("%d %d",A,B);
		
		
		
		return 0;
	}
