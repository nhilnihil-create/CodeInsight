#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod=MOD) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod=MOD) {
    return modpow(a, mod - 2, mod);
}

long long fac[100010], finv[100010], inv[100010];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < 100010; i++){
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

int main() {
    int n;
    cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    COMinit();
    ll ans=0;
    rep(d,61){
        ll c1=0,c0=0;
        rep(i,n){   
            if(a[i] & 1LL<<d) c1++;
            else c0++;
        }
        ll cnt=(c0*c1)%MOD;
        ll tmp=(cnt*modpow(2,d))%MOD;
        ans=(ans+tmp)%MOD;
    }

    cout<<ans<<endl;
}