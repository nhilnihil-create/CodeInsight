#include <cstdio>

int n, m;

int main() 
{
	scanf("%d%d", &n, &m);
	if (n & 1) for (int i = 0; i < m; ++i) printf("%d %d\n", i + 1, n - 1 - i);
	else {
		int k = (m - 1) / 2 + 1;
		for (int i = 0; i < k; ++i) printf("%d %d\n", i + 1, n - i);
		for (int i = k; i < m; ++i) printf("%d %d\n", i + 1, n - i - 1);
	}
	return 0;
}
