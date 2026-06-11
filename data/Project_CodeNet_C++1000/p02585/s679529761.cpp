#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

namespace IO {
    #define gc getchar()
    template <typename T>
    inline void read(T& x) {
        x = 0; bool f = 1; char ch;
        for (ch = gc; ch < '0' || '9' < ch; ch = gc) if (ch == '-') f ^= 1;
        for (; '0' <= ch && ch <= '9'; ch = gc) x = (x << 3) + (x << 1) + (ch ^ 48);
        x = f ? x : -x;
    }
    #undef gc
}

typedef long long ll;

const int MAXN = 1e6 + 10;

int n, k, nxt[MAXN], len[MAXN];
ll val[MAXN], sum[MAXN << 1], f[MAXN << 1], arr[MAXN << 1], fans = -LONG_LONG_MAX;

bool vis[MAXN];

int m;

void work(int st) {
    m = 0;
    int cur = nxt[st];
    while (1) {
        arr[++m] = val[cur], vis[cur] = true;
        if (cur == st) break;
        cur = nxt[cur];
    }
    rep(i, 1, m) arr[++m] = arr[i];
    rep(i, 1, m) sum[i] = sum[i - 1] + arr[i];
    int mxlen = min(m >> 1, k);
    ll mxval = -LONG_LONG_MAX; int mxval_len = 0;
    rep(i, 1, m) {
        f[i] = -LONG_LONG_MAX;
        rep(j, max(i - mxlen, 0), i - 1) {
            f[i] = max(sum[i] - sum[j] + 1ll * max(sum[m >> 1], 0ll) * ((k - i + j) / (m >> 1)), f[i]);
        }
        mxval = max(f[i], mxval);
    }
    fans = max(fans, mxval);
}

int main() {
    IO::read(n), IO::read(k);
    rep(i, 1, n) IO::read(nxt[i]);
    rep(i, 1, n) IO::read(val[i]);
    rep(i, 1, n) if (!vis[i]) {
        work(i);
    }
    printf("%lld\n", fans);
    return 0;
}