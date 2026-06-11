#include <stdio.h>

int main()
{	
	int A, B, C;
		scanf("%d", &A);
	C = A / 2;
	
	(B = A % 2 == 0) ? printf("%d", C) : printf("%d", C + 1);
	
	return 0;
}