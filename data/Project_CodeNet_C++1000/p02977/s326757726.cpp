#include <bits/stdc++.h>

int main() {
	int n; std::cin >> n;
	if ((n & -n) == n) { puts("No"); return 0; }
	puts("Yes");
	for (int i = 1; i < 3; ++ i) printf("%d %d\n", i, i + 1), printf("%d %d\n", i + n, i + n + 1);
	printf("%d %d\n", 3, n + 1);
	for (int i = 4; i < n; i += 2) {
		printf("%d %d\n", i, 1); printf("%d %d\n", i + 1, 1);
		printf("%d %d\n", i + n, i + 1); printf("%d %d\n", i, i + n + 1);
	}
	if (n & 1) return 0;
	int k = 1;
	while (k <= n) k <<= 1; k >>= 1;
	printf("%d %d\n", k ^ 1, n);
	printf("%d %d\n", n ^ k, 2 * n);
	return 0;
}
