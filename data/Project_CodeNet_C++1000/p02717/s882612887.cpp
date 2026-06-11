#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	if (!(1 <= x && x <= 100) &&
		!(1 <= y && y <= 100) &&
		!(1 <= z && z <= 100))
		{
			return 0;
		}
	swap(&x, &y);
	swap(&x, &z);
	printf("%d %d %d\n", x, y, z);
	return 0;
}