#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read() {
    int x = 0, fh = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            fh = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    return x * fh;
}
const int N = 2e5 + 10;
int n, x, y, i, a[N], b[N];
int kmax(int a, int b, int c, int d) { return max(max(max(a, b), c), d); }
int main() {
	n = read();
	for (i = 1; i <= n; i++) {
		x = read(); y = read();
		a[i] = x + y;
		b[i] = x - y;
	}
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
	cout << kmax(a[n] - a[1], b[n] - b[1], b[1] - b[n], a[1] - a[n]);
	return 0;
}