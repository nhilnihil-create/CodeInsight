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

const int MAXN = 2e5 + 10;

int n;
ll ans;

int main() {
    IO::read(n);
    rep(i, 1, n) ans += 1ll * (n - i + 2) * (n - i + 1) / 2;
    rep(i, 1, n - 1) {
        int a, b;
        IO::read(a), IO::read(b);
        if (a > b) swap(a, b);
        ans -= 1ll * a * (n - b + 1);
    }
    printf("%lld\n", ans);
    return 0;
}