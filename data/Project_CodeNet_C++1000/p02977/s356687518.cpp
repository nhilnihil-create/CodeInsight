#include <bits/stdc++.h>
using namespace std;

namespace TYC
{
	void work()
	{
		int n, p;
		scanf("%d", &n);
		for (p = 0; (1 << p) <= n; p++)
			if ((1 << p) == n)
				return void(puts("No"));
		puts("Yes");
		p--;
		printf("%d %d\n", 1, 2);
		printf("%d %d\n", 2, 3);
		printf("%d %d\n", 3, n + 1);
		printf("%d %d\n", n + 1, n + 2);
		printf("%d %d\n", n + 2, n + 3);
		for (int i = 4; i < n; i += 2)
		{
			printf("%d %d\n", n + 1, i);
			printf("%d %d\n", i, i + 1);
			printf("%d %d\n", n + 1, n + i + 1);
			printf("%d %d\n", n + i + 1, n + i);
		}
		if (n % 2 == 0)
		{
			printf("%d %d\n", 1 << p, n); 
			if (n - (1 << p) + 1 == 3)
				printf("%d %d\n", 3, n << 1);
			else
				printf("%d %d\n", (n << 1) - (1 << p) + 1, n << 1); 
		}
	}
}

int main()
{
	TYC::work();
	return 0;
}