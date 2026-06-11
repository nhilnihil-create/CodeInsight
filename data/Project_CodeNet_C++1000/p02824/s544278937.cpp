#include <bits/stdc++.h>

#define int long long

inline int in() { int t = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    do { t = t * 10 + ch - '0'; ch = getchar(); } while (ch >= '0' && ch <= '9');
    return t * f;
}

const int N = 1e5 + 5;

int n, m, v, p, a[N], nums[N], b[N], head[N];

signed main() {
    n = in(), m = in(), v = in(), p = in();
    for (int i = 1; i <= n; ++i) a[i] = in();
    std ::sort(a + 1, a + n + 1, std ::greater<int>());
    head[0] = 1;
    for (int i = 1; i <= n; ++i) {
        head[i] = head[i - 1];
        if (a[i] != a[head[i]]) head[i] = i;
        ++nums[head[i]];
    }
    int ans = head[p] - 1 + nums[head[p]], now = 0, nnum = nums[head[p]];
    for (int i = head[p] + nums[head[p]]; i <= n; ++i) {
        if (a[i] + m < a[p]) break;
        if (v <= n - nnum) ++ans;
        else {
            long long cur = m * (v - n + nnum) - now;
            cur = (cur + nnum - 1) / nnum;
            if (a[i] + m >= a[p] + cur) ++ans;
        }
        now += std ::min(m, a[p] - a[i]), ++nnum;
    }//打发士
    /*    for (int i = head[p] + nums[head[p]]; i <= n; ++i) {
            if (a[i] + m < a[p]) break;
            if (v <= n - nums[head[p]]) { ++ans; continue; }
            long long cur = m * (v - n + nums[head[p]]);
            cur = (cur + nums[head[p]] - 1) / nums[head[p]];
            if (a[i] + m >= a[p] + cur) ++ans;
        }*/
    std ::cout << ans << std ::endl;
    return 0;
}
