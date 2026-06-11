#include <bits/stdc++.h>
using namespace std;

int n;

bool check () {
	for (int i = 1; i <= n; i <<= 1) {
		if (i == n) return true;
	}
	return false;
}
int main () {
	scanf("%d", &n);
	bool flag = check();
	if (check()) {
		printf("No\n");
		return 0;
	}
	else {
		printf("Yes\n");
		printf("%d %d\n", 1, 2);
		printf("%d %d\n", 2, 3);
		printf("%d %d\n", 3, n + 1);
		printf("%d %d\n", n + 1, n + 2);
		printf("%d %d\n", n + 2, n + 3);

		int n_ = n - (n & 1 ^ 1);
		for (int i = 4; i <= n_; i += 2) {
			printf("%d %d\n", n + 1, n + i);
			printf("%d %d\n", n + i, n + i + 1);
			printf("%d %d\n", n + 1, i + 1);
			printf("%d %d\n", i + 1, i);
		}

		if (n & 1 ^ 1) {
			int x, y;
			for (int i = 2; i < n; i++) {
				if ((n ^ 1 ^ i) >= 2 && (n ^ 1 ^ i) < n) {
					x = i, y = n ^ 1 ^ i;
				}
			}
			if (x & 1 ^ 1) x += n;
			if (y & 1 ^ 1) y += n;
			printf("%d %d\n", n, x);
			printf("%d %d\n", n << 1, y);
		}
	}
	return 0;
}