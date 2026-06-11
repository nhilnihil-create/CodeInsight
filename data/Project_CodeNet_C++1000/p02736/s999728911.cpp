#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000010;

int binom(int n, int m) {
	for (int i = 0; i < 20; i++) {
		int x = n & (1<<i), y = m & (1<<i);
		if (!x && y) return 0;
	}
	return 1;
}

char str[maxn];
int a[maxn], n;

int main() {
	scanf("%d", &n);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++) a[i] = int (str[i] - '1');
	int f = 0;
	for (int i = 1; i <= n; i++) if (a[i] == 1) f = 1;
	if (f) {
		int s = 0;
		for (int i = 1; i <= n; i++) {
			s += (binom(n-1, i-1) * a[i]) & 1;
		}
		printf("%d\n", s & 1);
	} else {
		int s = 0;
		for (int i = 1; i <= n; i++) s += (binom(n-1, i-1) * (a[i] / 2)) & 1;
		printf("%d\n", (s & 1) * 2);
	}
	return 0;
}