#include <stdio.h>

int main()
{
	int H, A, X=0;
	scanf("%d%d", &H, &A);
	while(H>0)
	{
		H=H-A;
		X++;
	}
	printf("%d", X);
	return 0;
}