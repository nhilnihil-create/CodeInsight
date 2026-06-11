#include <iostream>

int n;

int main() {
//	freopen("code.in", "r", stdin);
//	freopen("code.out", "w", stdout);

	scanf("%d", &n);
	if (n == (n & -n)) return printf("No"), 0;
	printf("Yes\n");
	for (int i = 2; i < n; i += 2)
		printf("1 %d\n1 %d\n%d %d\n%d %d\n", i, i + 1, i, n + i + 1, i + 1, n + i);
	printf("%d %d\n", n + 1, n + 3);
	if (n % 2 == 0)
		for (int i = 2; i < n; ++i)
			if ((n ^ i ^ 1) < n) { printf("%d %d\n%d %d\n", i, n, n ^ i ^ 1, 2 * n); break; }
	return 0;
}
