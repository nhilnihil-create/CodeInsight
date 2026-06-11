#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC return 0;
using namespace std;
typedef long long i64;
const i64 MOD(1e9 + 7);
inline i64 Powlog(i64 a, i64 b) {
    i64 res(1);
    while (b) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
i64 n, a, b, kf, res;
i64 CNK(i64 n, i64 k) {
    i64 r(1), kf(1);
    for (int i = 0; i < k; ++i)
        r = (r * (n - i)) % MOD;
    kf = 1;
    for (int i = 1; i <= k; ++i)
        kf = (kf * i) % MOD;
    kf = Powlog(kf, MOD - 2);
    r = (r * kf) % MOD;
    return r;
}
int main() {
    DAU
    cin >> n >> a >> b;
    res = Powlog(2, n) - 1 - CNK(n, a) - CNK(n, b);
    while (res < 0)
        res += MOD;
    cout << res;
    PLEC
}
