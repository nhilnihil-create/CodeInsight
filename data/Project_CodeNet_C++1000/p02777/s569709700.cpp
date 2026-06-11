#include <stdio.h>
#include <string.h>

int main()
{
	int A, B; 
	char S[255], T[255], U[255];
	scanf("%s %s", &S,&T);
	scanf("%d %d" ,&A,&B);
	scanf("%s", &U);
	
	if(strcmp(S, U)==0) 
	{
		A--;
	}
	else if(strcmp(T, U)==0)
	{
		B--;
	}
	
	printf("%d %d", A, B);
	return 0;
}