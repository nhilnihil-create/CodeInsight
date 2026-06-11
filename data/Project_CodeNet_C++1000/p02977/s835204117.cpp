#include <bits/stdc++.h>

int main() {
	int n;
	scanf("%d", &n);
	if (__builtin_popcount(n) == 1) {
		puts("No");
		return 0;
	}
	puts("Yes");
	printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n", n + 1, n + 1, n + 2, n + 2, n + 3);
	for (int i = 4; i < n; i += 2) {
		printf("1 %d\n", i);
		printf("%d %d\n", i, i + n + 1);
		printf("1 %d\n", i + 1);
		printf("%d %d\n", i + 1, i + n);
	}
	if ((n & 1) == 0) {
		for (int i = 2; i <= n; ++i) {
			int j = i ^ n ^ 1;
			if (i != 3 && j != 3 && j <= n) {
				printf("%d %d\n%d %d\n", i, n, j, 2 * n);
				break;
			}
		}
	}
}