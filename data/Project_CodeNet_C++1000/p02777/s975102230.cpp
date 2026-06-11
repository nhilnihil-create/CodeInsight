#include<stdio.h>
#include<string.h>

int main()
{
	char S[11];
	char T[11];
	
	scanf("%s", S);
	scanf("%s", T);
	
	int A,B;
	scanf("%d", &A);
	scanf("%d", &B);
	
	char U[10];
	scanf("%s", U);
	
	if(strcmp(U,S)==0) printf("%d %d", A-1,B);
	if(strcmp(U,T)==0) printf("%d %d", A,B-1);
	
	return 0;
}