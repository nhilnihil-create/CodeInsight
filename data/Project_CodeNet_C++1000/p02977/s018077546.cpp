#include <cstdio>
#define add(x, y) printf("%d %d\n", x, y);
int main()
{
	int n;
	scanf("%d", &n);
	if (__builtin_popcount(n) == 1)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	add(1, 2);
	add(2, 3);
	add(n + 3, 1);
	add(n + 3, n + 2);
	add(n + 2, n + 1);
	for (int i = 4; i + 1 <= n; i += 2)
	{
		add(1, i);
		add(i, i + 1);
		add(1, n + i + 1);
		add(n + i + 1, n + i);
	}
	if (n & 1 ^ 1)
	{
		for (int i = 2; i < n; i++)
		{
			int j = n ^ 1 ^ i;
			if (j < n && j >= 2 && i != j)
			{
				add(i + (i & 1) * n, n);
				add(j + (j & 1) * n, n * 2);
				return 0;
			}
		}
	}
	return 0;
}
