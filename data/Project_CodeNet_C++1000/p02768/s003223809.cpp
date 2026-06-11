#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define ll long long
const int MOD = 1e9+7;


long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

ll COM(ll n, ll k) {
    ll x = 1;
    for(ll i=n-k+1; i<=n; i++) {
        x = x*i%MOD;
    }

    ll y = 1;
    for(ll i=1; i<=k; i++) {
        y = y*i%MOD;
    }
    y = modpow(y, MOD-2);

    return x*y%MOD;
}

int main(){
    ll n,a,b; cin >> n >> a >> b;
    ll ans = modpow(2,n)-1;
    ans%=MOD;
    ans -= (COM(n,a)+COM(n,b))%MOD;
    ans%=MOD;
    if(ans<0) ans+=MOD;
    cout << ans << endl;
}