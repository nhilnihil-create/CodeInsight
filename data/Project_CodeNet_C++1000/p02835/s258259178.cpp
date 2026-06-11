#include <stdio.h>

int main()
{
	int A1, A2, A3, A4, check;
	
	scanf("%d%d%d", &A1, &A2, &A3);
	A4 = A1+A2+A3;
	
	check=A4;
	if(check>=22)
	{
		printf("bust");
	}
	else
	{
		printf("win");
	}
	return 0;
}