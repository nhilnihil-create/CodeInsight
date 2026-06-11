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

inline void printEdge(int u, int v) {//输出无向边 u -> v
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
	for (int i = 2; i + 1 <= n; i += 2) {
		printEdge(1, i), printEdge(i, i + 1);
		printEdge(1, i + n + 1), printEdge(i + n + 1, i + n);
		//对于每组 { x, x ^ 1 } 连边 
	}
	printEdge(3, n + 1);//把 n + 1 接在 3 的下面 
	if (!(n & 1)) {// n 是偶数 
		for (int i = 0; (1 << i) <= n; ++i)
			if (n & (1 << i)) bit = i;
		printEdge(n ^ (1 << bit), n), printEdge(((1 << bit) ^ 1) + n, n << 1);
	}
	return 0;
}