#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 1000006;

template <typename T> inline void read(T &AKNOI) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	AKNOI = flag * x;
}

template <typename T> inline void cmin(T &x, T y) {
	if (x > y) x = y;
}

template <typename T> inline void cmax(T &x, T y) {
	if (x < y) x = y;
}

char s[MAXN];
int n, a[MAXN];

inline bool C(int x, int y) {
	return ((x & y) == y);
}

void init() {
	read(n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) {
		a[i] = s[i] - '0' - 1;
	}
}

void solve() {
	if (n == 2) {
		printf("%d\n", abs(a[1] - a[2]));
		return;
	}
	int ans = 0, h1 = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 1) {
			ans ^= C(n - 1, i - 1);
			h1 = 1;
		}
	}
	if (ans) {
		printf("1\n");
		return;
	}
	if (h1) {
		printf("0\n");
		return;
	}
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == 2) {
			ans ^= C(n - 1, i - 1);
		}
	}
	printf("%d\n", ans * 2);
}

int main() {
	init();
	solve();
	return 0;
}
