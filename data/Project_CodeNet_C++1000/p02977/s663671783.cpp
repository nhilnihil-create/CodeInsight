#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>

int n, m;

int inline Log(int a)
{
	int l = 0, r = 31;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if ((1 << mid) >= a)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return l;
}

int main() 
{
	scanf("%d", &n);
	m = Log(n);
	if ((1 << m) == n)
	{
		puts("No");
	}
	else
	{
		puts("Yes");
		printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n", 1, 2, 2, 3, 3, n + 1, n + 1, n + 2, n + 2, n + 3);
		for (int i = 2; (i << 1 | 1) <= n; i++)
		{
			printf("%d %d\n", 1, i << 1);
			printf("%d %d\n", 1, i << 1 | 1);
			printf("%d %d\n", i << 1, (i << 1 | 1) + n);
			printf("%d %d\n", i << 1 | 1, (i << 1) + n);
		}
		if (!(n & 1))
		{
			for (int i = 2; i < n; i++)
			{
				if (i != 3)
				{
					int j = (i ^ 1 ^ n);
					if (j != 3 && j < n)
					{
						printf("%d %d\n", n, i);
						printf("%d %d\n", n << 1, j);
						break;
					}
				}
			}
		}
	}
	return 0;
}