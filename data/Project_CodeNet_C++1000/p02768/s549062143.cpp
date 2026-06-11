#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1000000007;

vector<ll> inv,finv;
void COMinit(ll siz) {
    ll buf=5;
    inv.resize(siz+buf);
    finv.resize(siz+buf);

    finv[0]=finv[1]=1;
    inv[1]=1;

    for (int i = 2; i < siz+buf; i++){
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    ll ans=1;
    for(ll i = n; i >= n-k+1; i--) {
        ans*=i;
        ans%=MOD;
    }
    ans*=finv[k];
    return ans%MOD;
}

ll modpow(ll a, ll n, ll mod){
    ll res=1;
    while(n>0){
        if(n&1) res=res*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return res;
}

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b;
    cin >> n >> a >> b;

    COMinit(max(a,b));
    ll ans=modpow(2,n,MOD)-1;
    ans-=COM(n,a);
    if(ans<0) ans+=MOD;
    ans-=COM(n,b);
    if(ans<0) ans+=MOD;

    cout << ans << "\n";

    return 0;
}