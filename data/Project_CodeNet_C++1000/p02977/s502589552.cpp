#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <class T>
inline void read(T &x) {
    x = 0;
    char c = getchar();
    bool f = 0;
    for (; !isdigit(c); c = getchar()) f ^= c == '-';
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    x = f ? -x : x;
}

template <class T>
inline void write(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    T y = 1;
	int len = 1;
    for (; y <= x / 10; y *= 10) ++len;
    for (; len; --len, x %= y, y /= 10) putchar(x / y + 48);
}

int n, m, bit;

inline void printEdge(int u, int v) {
	write(u);
	putchar(' ');
	write(v);
	putchar('\n');
}

int main() {
	read(n);
	for (int i = 0; (1 << i) <= n; ++i)
		if (n == (1 << i)) {
			puts("No");
			return 0;
		}
	puts("Yes");
	printEdge(1, 2), printEdge(2, 3), printEdge(3, n + 1);
	printEdge(n + 1, n + 2), printEdge(n + 2, n + 3);
	for (int i = 4; i + 1 <= n; i += 2) {
		printEdge(1, i), printEdge(i, i + 1);
		printEdge(1, i + n + 1), printEdge(i + n + 1, i + n);
	}
	if (!(n & 1)) {
		for (int i = 0; (1 << i) <= n; ++i)
			if (n & (1 << i)) bit = i;
		printEdge(((1 << bit) ^ 1) + n, n), printEdge(n ^ (1 << bit), n << 1);
	}
	return 0;
}