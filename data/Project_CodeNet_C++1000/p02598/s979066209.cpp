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

int n, k, arr[MAXN];

bool check(int x) {
    ll cnt = 0;
    rep(i, 1, n) cnt += (arr[i] - 1) / x;
    return cnt <= k;
}

int main() {
    IO::read(n), IO::read(k);
    rep(i, 1, n) IO::read(arr[i]);
    int l = 1, r = *max_element(arr + 1, arr + n + 1), ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}