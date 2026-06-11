#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

// a^n mod を計算する
// O(logn)
ll modpow(ll a, ll n, ll mod=MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// nCr mod を計算する O(n)
const int MAX_N = 1000010;
ll fac[MAX_N], finv[MAX_N], inv[MAX_N];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX_N; i++){
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

int main(){
    ll n,a,b;
    cin>>n>>a>>b;

    ll ans=modpow(2,n);

    COMinit();
    ll tmpa=finv[a];
    for(int i=0;i<=a-1;i++){
        tmpa=(tmpa*(n-i))%MOD;
    }
    ll tmpb=finv[b];
    for(int i=0;i<=b-1;i++){
        tmpb=(tmpb*(n-i))%MOD;
    }

    ans=(ans+MOD-1)%MOD;
    ans=(ans+MOD-tmpa)%MOD;
    ans=(ans+MOD-tmpb)%MOD;

    cout<<ans<<endl;
}

