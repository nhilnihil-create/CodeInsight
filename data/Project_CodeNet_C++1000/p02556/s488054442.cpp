#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, N = 2e5 + 5;
int n, x, y;
int a[N], b[N];
inline int read () {
    int tot = 0, f = 1; char c = getchar ();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar (); }
    while (c >= '0' && c <= '9') { tot = tot * 10 + c - '0'; c = getchar ();}
    return tot * f;
}
signed main () {
    n = read ();
    for (int i = 1; i <= n; i++) {
        x = read (); y = read ();
        a[i] = x - y;
        b[i] = x + y;
    }
    sort (a + 1, a + 1 + n); sort (b + 1, b + 1 + n);
    printf ("%d\n", max (a[n] - a[1], b[n] - b[1]));
    return 0;
}
