#include<stdio.h>
#include<string.h>

int main()
{
	
	char S[15];
	char U[15];
	char T[15];
	int A;
	int B;
	scanf("%s %s %d %d %s",&S,&T,&A,&B,&U);
	if(strcmp(U,S)==0)
	{
		printf("%d %d",A - 1,B);
	}
	if(strcmp(U,T)==0)
	{
		printf("%d %d",A,B - 1);
	}
	
	return 0;	
}
	