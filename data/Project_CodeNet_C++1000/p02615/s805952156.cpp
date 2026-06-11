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

int n, arr[MAXN];
ll ans;

int main() {
    IO::read(n);
    rep(i, 1, n) IO::read(arr[i]);
    sort(arr + 1, arr + n + 1), reverse(arr + 1, arr + n + 1);
    ans += arr[1];
    int cnt = 1, i = 2;
    while (cnt <= n - 1) {
        if (cnt == n - 1) break;
        ans += 1ll * min(2, n - 1 - cnt) * arr[i];
        i++, cnt += min(2, n - 1 - cnt);
    }
    printf("%lld\n", ans);
    return 0;
}