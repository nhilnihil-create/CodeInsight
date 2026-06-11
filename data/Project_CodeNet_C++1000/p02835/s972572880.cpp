#include <stdio.h>
int main()
{
	int A1, A2, A3;
	int Sum;
	scanf("%d %d %d", &A1, &A2, &A3);
	Sum = A1 + A2 + A3;
		if (Sum>=22)
		{
			printf("bust \n");
		}
		else if (Sum<22)
		{
			printf("win \n");
		}
	return 0;
}