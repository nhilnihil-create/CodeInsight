#include <bits/stdc++.h>

int n;

int main() {
	scanf("%d", &n);
	int QAQ = 1;
	for (; QAQ < n; QAQ <<= 1);
	if (QAQ == n) return puts("No"), 0;
	printf("Yes\n%d %d\n", n + 1, n + 3);
	for (int i = 2; i < n; i += 2) printf("%d %d\n%d %d\n%d %d\n%d %d\n", 1, i, 1, i + 1, i, n + i + 1, n + i, i + 1);
	if (n % 2 == 0) {
		for (int i = 2; i <= n; ++i) {
			int j = n ^ i ^ 1;
			if (j < n && j > 1) return printf("%d %d\n%d %d\n", i, n, j, n + n), 0;
		}
	}
	return 0;
}