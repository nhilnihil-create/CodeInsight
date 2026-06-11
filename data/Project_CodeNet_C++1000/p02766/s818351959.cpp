#include <stdio.h>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int count = 0;

	while (n != 0)
	{
		n /= k;
		count++;
	}

	printf("%d\n", count);
}