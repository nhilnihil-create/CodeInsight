#include <stdio.h>
#include <stdlib.h>

int	main()
{
	int	A, B, M;
	int	*a, *b, min, numa, numb;
	int	x, y, c, sum;

	scanf("%d %d %d\n", &A, &B, &M);
	a = (int *)malloc(sizeof(int) * (A + 1));
	b = (int *)malloc(sizeof(int) * (B + 1));
	min = 10001;
	for (int i = 0; i < A; i++)
	{
		scanf("%d ", &a[i]);
		if (a[i] < min)
		{
			min = a[i];
			numa = i;
		}
	}
	min = 10001;
	for (int i = 0; i < B; i++)
	{
		scanf("%d ", &b[i]);
		if (b[i] < min)
		{
			min = b[i];
			numb = i;
		}
	}
	min = a[numa] + b[numb];
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &x, &y, &c);
		sum = a[x - 1] + b[y - 1] - c;
		if (sum < min)
			min = sum;
	}
	printf("%d\n", min);
	return (0);
}