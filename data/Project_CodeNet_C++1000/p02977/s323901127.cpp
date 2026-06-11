#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;
const int N = 200005;

inline int input() {
	int x; char ch; while (!isdigit(ch = getchar()));
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	return x;
}

inline void chkmin(int &x, int y) { x = x < y ? x : y; }

int n, m;
int a[N];

int main() {
#ifdef local
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
//	freopen("log", "w", stderr);
#endif
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i <= 30; ++i)
		if ((1 << i) == n) return puts("No"), 0;
	puts("Yes");

	if (n % 4 == 0) {
		for (int i = 1; i < n; ++i) a[i] = i;
		swap(a[(n & -n) - 1], a[n ^ (n & -n)]);
		printf("%d %d\n", n, n & -n);
		printf("%d %d\n", n + n, n ^ (n & -n));
		for (int i = 1; i < n - 1; ++i) {
			printf("%d %d\n", a[i], a[i + 1]);
			printf("%d %d\n", n + a[i], n + a[i + 1]);
		}
		printf("%d %d\n", a[n - 1], n + a[1]);
		return 0;
	}

	if (n % 4 == 1) {
		for (int i = 2; i < n; ++i) {
			printf("%d %d\n", i, i + 1);
			printf("%d %d\n", n + i, n + i + 1);
		}
		printf("%d %d\n", n, n + 2);
		printf("%d %d\n", 1, 2);
		printf("%d %d\n", n + 1, 3);
		return 0;
	}

	if (n % 4 == 2) {
		printf("%d %d\n", 3, 2);
		printf("%d %d\n", 2, 4);
		printf("%d %d\n", n + 3, n + 2);
		printf("%d %d\n", n + 2, n + 4);
		for (int i = 4; i < n - 1; ++i) {
			printf("%d %d\n", i, i + 1);
			printf("%d %d\n", n + i, n + i + 1);
		}
		printf("%d %d\n", n - 1, n + 3);
		printf("%d %d\n", 1, 2);
		printf("%d %d\n", n + 1, 3);
		printf("%d %d\n", n - 1, n);
		printf("%d %d\n", n + 3, n + n);
		return 0;
	}

	if (n % 4 == 3) {
		for (int i = 1; i < n << 1; ++i)
			printf("%d %d\n", i, i + 1);
		return 0;
	}
}