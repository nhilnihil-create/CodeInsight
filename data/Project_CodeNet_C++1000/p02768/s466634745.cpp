#include <bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1000000007;
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

const int MAX = 210000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long ncr(int n, int k){
    int64_t numerator = 1;
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    
    for(int64_t i=n;i>=(n-k+1);i--) {
        numerator = (numerator * i) % MOD;
    }
    return numerator * finv[k] % MOD;
}

int main(void) {
    int64_t n,a,b;
    int64_t ans;
    cin >> n >> a >> b;

    COMinit();
//cout << modpow(2,n,MOD) << endl;
//cout << ncr(n,a) << endl;
//cout << ncr(n,b) << endl;
    ans = (modpow(2,n,MOD)-1- ncr(n,a) - ncr(n,b));
    ans %= MOD;

    if(ans < 0) ans = MOD + ans;
    ans %= MOD;

    cout << ans << "\n";
    return 0;
}
