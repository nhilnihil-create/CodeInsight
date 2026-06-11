#include <stdio.h>

int main()
{
	int A1, A2, A3;
	scanf ("%d %d %d", &A1, &A2, &A3);
	(A1 + A2 + A3 >= 22) ? puts("bust") : puts ("win");
	return 0;
}