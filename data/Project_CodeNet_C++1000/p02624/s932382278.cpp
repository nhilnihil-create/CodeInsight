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

const int MAXN = 1e7 + 10;

int is_prime[MAXN], cnt[MAXN], prime[MAXN], p_cnt, num[MAXN];

void sieve() {
    cnt[1] = 1, num[1] = 0;
    rep(i, 2, MAXN) {
        if (!is_prime[i]) prime[++p_cnt] = i, cnt[i] = 2, num[i] = 1;
        rep(j, 1, p_cnt) {
            if (i * prime[j] > MAXN) break;
            is_prime[i * prime[j]] = true;
            if (i % prime[j]) {
                cnt[i * prime[j]] = cnt[i] << 1;
                num[i * prime[j]] = 1;
            } else {
                num[i * prime[j]] = num[i] + 1;
                cnt[i * prime[j]] = 1ll * cnt[i] / num[i * prime[j]] * (num[i * prime[j]] + 1);
                break;
            }
        }
    }
}

int n;

int main() {
    sieve();
    IO::read(n);
    long long ans = 0;
    rep(i, 1, n) {
        ans += 1ll * i * cnt[i];
    }
    printf("%lld\n", ans);
    return 0;
}