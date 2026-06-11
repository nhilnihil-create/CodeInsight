#include <stdio.h>
#include <string.h>

int main()
{
	int A, B;
	char P[40];
	char Q[40];
	char R[40];
	
	scanf("%s %s", &P, &Q);
	scanf("%d %d", &A, &B);
	scanf("%s", &R);
	
	if(strcmp(P, R)==0)
{
	A--;
	printf("%d %d", A, B);
}
	else
{
	B--;
	printf("%d %d", A, B);
}
	return 0;
}