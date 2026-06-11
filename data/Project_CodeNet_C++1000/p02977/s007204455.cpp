#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	scanf("%d", &n);
	if (n == (n & -n)){
		printf("No"); return 0;
	}
	puts("Yes");
	printf("%d %d\n", 1, 2);
	printf("%d %d\n", 2, 3);
	printf("%d %d\n", 3, n + 1);
	printf("%d %d\n", n + 1, n + 2);
	printf("%d %d\n", n + 2, n + 3);
	for (int i = 4; i + 1 <= n; i += 2) {
		printf("%d %d\n", i, i + 1);
		printf("%d %d\n", i + n, i + n + 1);
		printf("%d %d\n", n + 1, i + 1);
		printf("%d %d\n", n + 1, i + n);
	}
	if (~n & 1) {
		for (int i = 2; i < n; ++i) {
			int x = i, y = n ^ i ^ 1;
			if (y >= 2 && y < n && x != y) {
				printf("%d %d\n", n, x & 1 ? x : x + n);
				printf("%d %d\n", n + n, y & 1 ? y : y + n);
				break;
			}
		}
	}
}
