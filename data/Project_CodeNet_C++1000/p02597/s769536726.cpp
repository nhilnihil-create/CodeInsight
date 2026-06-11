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

const int MAXN = 200000 + 10;

int n, arr[MAXN], cnt1, ans;
char str[MAXN];

int main() {
    IO::read(n);
    scanf("%s", str + 1);
    rep(i, 1, n) arr[i] = (str[i] == 'R');
    rep(i, 1, n) cnt1 += arr[i];
    rep(i, 1, cnt1) ans += !arr[i];
    printf("%d\n", ans);
    return 0;
}