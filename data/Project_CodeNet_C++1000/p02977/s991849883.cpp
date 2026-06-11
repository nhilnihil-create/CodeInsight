#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
	scanf("%d", &n);
	if ((n & -n) == n)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	int m = 1 << (int)log2(n), k = n - m;
	printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n", 1, m, 1, m + 1, m + 1, m + n, m + n, n + 1, n + 1, n + m + 1);
	for (int i = 2; i < n; i += 2)
		if (i != m)
			printf("%d %d\n%d %d\n%d %d\n%d %d\n", 1, i, 1, i + 1, i, n + i + 1, i + 1, n + i);
	if (!(n & 1))
		printf("%d %d\n%d %d\n", m + 1, n, k, 2 * n);
	return 0;
}
