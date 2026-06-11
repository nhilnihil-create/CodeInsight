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

const int MAXN = 100000 + 10;

int n, m, fa[MAXN];

int gf(int x) { return fa[x] == x ? x : fa[x] = gf(fa[x]); }

int main() {
    IO::read(n), IO::read(m);
    rep(i, 1, n) fa[i] = i;
    rep(i, 1, m) {
        int a, b;
        IO::read(a), IO::read(b);
        if (fa[gf(a)] != fa[gf(b)]) fa[gf(a)] = gf(b);
    }
    int ans = 0;
    rep(i, 1, n) {
        if (fa[i] == i) ans++;
    }
    printf("%d", ans - 1);
    return 0;
}