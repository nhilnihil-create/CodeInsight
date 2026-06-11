// Create time: 2019-08-24  20:36:56
#include <bits/stdc++.h>
#define rint register int
#define N 400005
using namespace std;
const int Mod = 1e9 + 7;

int n, a[N], c[N], d[N], x[N], y[N], q, p;
char s[N];
int main() {
#ifdef whyqx
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif
    cin >> n;
    scanf("%s", s + 1);
    for (rint i = 1; i <= n * 2; ++i)
        a[i] = (s[i] == 'B');
    for (rint i = 1; i <= n * 2 + 1; ++i)
        d[i] = a[i] ^ a[i - 1];
    c[1] = 0;
    for (rint i = 2; i <= n * 2; ++i)
        c[i] = !d[i] ? (c[i - 1] ^ 1) : c[i - 1];
    for (rint i = 1; i <= n * 2; ++i)
        if (c[i]) y[++p] = i;
        else x[++q] = i;
    if (d[1] == 0 || p != q) { puts("0"); return 0;}
    reverse(x + 1, x + q + 1);
    long long ans = 1, fac = 1;
    for (rint i = 1; i <= n; ++i) {
        int pos = upper_bound(y + 1, y + n + 1, x[i]) - y;
        ans = 1ll * ans * (n - pos + 1 - (i - 1)) % Mod;
        fac = 1ll * fac * i % Mod;
    }
    cout << 1ll * fac * ans % Mod;
    return 0;
}
