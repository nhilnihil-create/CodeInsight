#include <stdio.h>

int main()
{
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	if(A==B && B==C && C==A)
	{
		printf("No");
	}
	else if(A==B || B==C || C==A)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	return 0;
}