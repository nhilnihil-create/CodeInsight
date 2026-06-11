#include <stdio.h>

int main()
{
	int x; scanf ("%d", &x);
	int a = (x / 500) * 1000 + (x % 500) / 5 * 5;
	printf ("%d\n", a);

	return 0;
}