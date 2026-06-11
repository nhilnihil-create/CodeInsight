#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
int n;
int main()
{
	scanf("%d", &n);
	if (n & (n - 1))
	{
		puts("Yes");
		if (n % 4 == 3)
		{
			for (int i = 1; i < 2 * n; i++)
				printf("%d %d\n", i, i + 1);
			return 0;
		}
		if (n % 4 == 2)
		{
			printf("%d %d\n", n, n - 2);
			printf("%d %d\n", n - 2, 2);
			printf("%d %d\n", 2, n + n);
			printf("%d %d\n", n + n, n + n - 2);
			printf("%d %d\n", n + n - 2, n + 2);
			printf("%d %d\n", 2, 1);
			printf("%d %d\n", 1, n - 1);
			printf("%d %d\n", n + n, n + n - 1);
			printf("%d %d\n", n + n - 1, n + 1);
			for (int i = 3; i <= n - 3; i++)
			{
				printf("%d %d\n", i, i - 1);
				if (i != n - 3)
					printf("%d %d\n", n + i, n + i + 1);
			}
			printf("%d %d\n", n + n - 3, 1);
		}
		if (n % 4 == 1)
		{
			printf("%d %d\n", n, n - 1);
			printf("%d %d\n", n - 1, 1);
			printf("%d %d\n", 1, n + n);
			printf("%d %d\n", n + n, n + n - 1);
			printf("%d %d\n", n + n - 1, n + 1);
			for (int i = 2; i <= n - 2; i++)
			{
				printf("%d %d\n", i, i - 1);
				if (i != n - 2)
					printf("%d %d\n", n + i, n + i + 1);
			}
			printf("%d %d\n", n + n - 2, 1);
		}
		if (n % 4 == 0)
		{
			int v = n ^ (n - 1);
			printf("%d %d\n", n, n - 1);
			printf("%d %d\n", n - 1, v);
			printf("%d %d\n", v, n + n);
			printf("%d %d\n", n + n, n + n - 1);
			printf("%d %d\n", n + n - 1, n + v);
			int lst = v;
			for (int i = 1; i <= n - 2; i++)
			{
				if (i == v)continue;
				printf("%d %d\n", i, lst);
				if (lst != v)
					printf("%d %d\n", n + lst, n + i);
				lst = i;
			}
			printf("%d %d\n", n + lst, n - 1);
		}
	}
	else
		puts("No");
}
