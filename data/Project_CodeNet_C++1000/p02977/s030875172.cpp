#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
	f = 0; _T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

int n, base;

int main() {
	read(n);
	for (int i = 0; i <= 16; i++) {
		if (n < (1 << i)) break;
		base = i;
		if (n == (1 << i)) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for (int i = 2; i < n; i += 2) {
		printf("%d %d\n", 1, i);
		printf("%d %d\n", i, i + 1);
		printf("%d %d\n", 1, i + 1 + n);
		printf("%d %d\n", i + 1 + n, i + n);
	}
	printf("%d 3\n", n + 1);
	if (n % 2 == 0) {
		int x = (1 << base), y = n - x + 1;
		printf("%d %d\n", n, x);
		printf("%d %d\n", n * 2, y + n);
	}
	return 0;
}