#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
const int MAX = 1000010;
//const int MOD = 998244353;
const int MOD = 1000000007;
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
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    // 前処理
    COMinit();
    ll X,Y;
    cin >> X >> Y;
    // a+2b = X
    // 2a+b = Y
    // -> b = (2X-Y)/3
    // -> a = (2Y-X)/3
    if((2*X-Y)%3 != 0 || (2*Y-X)%3 != 0){
        cout << 0 << endl;
        return 0;
    }
    ll a = (2*Y-X)/3;
    ll b = (2*X-Y)/3;
    if(a<0||b<0){
        cout << 0 << endl;
        return 0;
    }
    ll ans = fac[a+b];
    ans*=finv[a];
    ans%=MOD;
    ans*=finv[b];
    ans%=MOD;
    cout << ans << endl;
    return 0;
}