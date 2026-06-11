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

const int MAXN = 1e6 + 10;
int k, m;
bool vis[MAXN];
int main() {
    scanf("%d", &k);
    m = 7 % k;
    int tmp = m;
    int ans = 1;
    while (1) {
        if (m == 0) {
            printf("%d\n", ans);
            return 0;
        }
        if (vis[m]) { puts("-1"); return 0; }
        ans++; vis[m] = true;
        m = (1ll * m * 10 + 1ll * tmp) % k;
    }
    return 0;
}