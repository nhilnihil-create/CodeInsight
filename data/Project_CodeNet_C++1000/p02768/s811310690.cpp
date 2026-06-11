#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define LCM(a, b) (a) / __gcd((a), (b)) * (b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define ln '\n'

using namespace std;
using LL = long long;
using ldouble = long double;
using P = pair<int, int>;
using LP = pair<LL, LL>;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1e9 + 7;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

LL fac[SIZE], finv[SIZE], inv[SIZE];
void combInit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < SIZE; ++i) {
        fac[i] = (fac[i - 1] * i) % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = (finv[i - 1] * inv[i]) % MOD;

    }
}

// 組み合わせ（重複無し）
LL comb(int n, int k) {
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return (fac[n] * (finv[k] * finv[n - k] % MOD)) % MOD;

}

LL Div(LL a, LL b) {
    LL exp = MOD - 2;
    while(exp) {
        if(exp % 2 != 0) {
            a = a * b % MOD;
        }
        b = b * b % MOD;
        exp >>= 1;
    }
    return a;
}

// 二項係数
LL Bin(LL n, LL k) {
    if(k < 0 || n < k) {
        return 0;

    }
    LL ret = 1;
    for(LL i = 1; i <= k; ++i) {
        ret *= n--;
        ret %= MOD;
        ret = Div(ret, i);

    }
    return ret;
}

// 重複組み合わせ
LL comb_rep(int x, int y) {
    return comb(x + y - 1, x - 1);

}

/*
 * 繰り返し自乗法
 */
//typedef long long LL;
LL power( LL x, LL n ) {
    LL res = 1;
    if( n > 0 ) {
        res = power( x, n / 2 );
        if( n % 2 == 0 ) res = ( res * res ) % MOD;
        else res = ( ( ( res * res ) % MOD ) * x ) % MOD;

    }
    return res;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    LL n, a, b;
    cin >> n >> a >> b;

    combInit();
    LL res = power(2ll, n);
    res = (res - Bin(n, a) + MOD) % MOD;
    res = (res - Bin(n, b) + MOD) % MOD;
    cout << res - 1 << endl;

    return 0;
}

