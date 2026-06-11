#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

using ll = long long;
using ull = unsigned long long;
using veci = vector<int>;
using vecll = vector<ll>;
using vecull = vector<ull>;

/* 二項係数 nCr mod p を計算する。

nCr = n! / (r! * (n -r)!)
    = n! * (r!)^{-1} * ((n-r)!)^{-1}
を利用する。

n!、(r!)^{-1}、((n-r)!)^{-1}は予め求めておく必要がある。
また、逆元^{-1}は拡張ユークリッドの互除法により求めることができる。

*/
#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;


constexpr int MAX = 1010000;
constexpr int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

// nCr 計算用初期化処理
// O(MAX)
void comb_init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;

    for(int i = 2; i < MAX; ++i) {
        fac[i] = fac[i - 1] * i % MOD; // 累乗の累積
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD; // 逆元
        finv[i] = finv[i - 1] * inv[i] % MOD; // 逆元の累積
    }
}

// nCr mod MOD を計算する。
// O(1)
ll comb(int n, int r) {

    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
}

ll X, Y;

int main(void) {

    comb_init();

    cin >> X >> Y;
    if (X < Y) swap(X, Y);

    if ((X + Y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    ll n = (X + Y) / 3;
    ll r = Y - n;

    cout << comb(n, r) << endl;

    return 0;
}
