#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void read (int &x) {
    char ch = getchar(); int f = 0; x = 0;
    while (!isdigit(ch)) { if (ch == '-') f = 1; ch = getchar(); }
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); if (f) x = -x;
} const int N = 1e5 + 10;
int n, a[N], sum, s[N], res[N], mx[N];
signed main() {
    read (n);
    for (int i = 0; i <= n; ++i) read (a[i]); 
    for (int i = n; i >= 0; --i)	 s[i] = s[i + 1] + a[i];
    if (n == 0) { a[0] == 1 ? puts ("1") : puts ("-1"); return 0; }
    res[0] = 1 - a[0], sum = 1;
    for (int i = 1; i <= n; ++i) {
    	res[i] = min (res[i - 1] * 2, s[i]);
		sum += res[i], res[i] -= a[i];
		if (res[i] < 0) return puts ("-1"), 0;
	} return printf ("%lld\n", sum), 0;
}
