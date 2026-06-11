#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	if (!(n & (n - 1)))
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	int m = n;
	printf("%d %d\n", 1 + n, 3);
	if (n % 2 == 0)
		m--;
	for(int i = 2; i < m; i += 2)
	{
		printf("%d %d\n", i, i + 1);
		printf("%d %d\n", i, 1);
		printf("%d %d\n", i + n, i + 1 + n);
		printf("%d %d\n", i + n + 1, 1);
	}
	if (n % 2 == 0)
	{
		int x = n & -n;
		int y = n - x;
		printf("%d %d\n", x, n);
		printf("%d %d\n", y + n + 1, n * 2);
	}
	return 0;
}