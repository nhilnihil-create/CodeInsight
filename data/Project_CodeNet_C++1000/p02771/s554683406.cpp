#include<stdio.h>
int main()
{
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	
	if(A==C && B==C && A==B) printf("No");
	else
	{
		if (A!=C && B!=C && A!=B)
		{
			printf("No");
		}
		else
		{
			printf("Yes");
		}
	}
	
	return 0;
}