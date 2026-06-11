#include<stdio.h>
#include<string.h>

 
 int main(){
 	char S[30],T[30];
 	int A, B;
 	char U[30];
 	scanf("%s %s", &S, &T );
 	scanf("%d %d", &A, &B );
 	scanf("%s", &U);
 	int com = strcmp(U,S);
 	int com2 = strcmp(U,T);
 	if(com == 0){
 		printf("%d %d", A-1, B);
	 }
	else if(com2 == 0){
		printf("%d %d", A, B-1);
	}
	return 0;
 }
 