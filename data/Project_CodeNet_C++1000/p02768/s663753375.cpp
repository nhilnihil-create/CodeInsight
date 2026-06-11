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

long long fac[200010], finv[200010], inv[200010];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < 200010; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

int main(){
    ll n,a,b;
    cin>>n>>a>>b;

    ll ans=modpow(2,n);
    ans-=1;
    if(ans<0) ans+=MOD;

    COMinit();

    ll tmp=1;
    for(ll i=0;i<=a-1;i++){
        tmp=(tmp*(n-i))%MOD;
    }
    tmp=(tmp*finv[a])%MOD;

    //cout<<tmp<<endl;
    ans-=tmp;
    if(ans<0) ans+=MOD;
    
    tmp=1;
    for(ll i=0;i<=b-1;i++){
        tmp=(tmp*(n-i))%MOD;
    }
    tmp=(tmp*finv[b])%MOD;
    //cout<<tmp<<endl;
    ans-=tmp;
    if(ans<0) ans+=MOD;

    cout<<ans<<endl;
}