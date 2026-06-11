#include <cstdio>

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int a = 0;
	int i;
	for (i = 0; i < m; i++) {
		int sc;
		scanf("%d", &sc);
		a += sc;
	}
	if (a > n)
		printf("-1\n");
	else
		printf("%d\n", n - a);
	
	return 0;
}