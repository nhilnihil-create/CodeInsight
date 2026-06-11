#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
const ll mod = 1000000007;
#define MAX_N 2200000
ll f[MAX_N+1];
ll invf[MAX_N+1];
ll modpow(ll  a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
ll nCm(ll n,ll m){return ((f[n]*invf[m])%mod)*invf[n-m]%mod;  }
signed main(){
    int n,a,b;cin >> n >> a >> b;
    int res = 1;
    int ans = modpow(2,n,mod) - 1;
    for(int shita = 1,ue = n-a+1;shita<=a;ue++,shita++){
        res = (res*ue)%mod;
        res = (res*modpow(shita,mod-2,mod))%mod;

    }
    ans -= res;
    res = 1;
    for(int shita = 1,ue = n-b+1;shita<=b;ue++,shita++){
        res = (res*ue)%mod;
        res = (res*modpow(shita,mod-2,mod))%mod;

    }
    ans -= res;
    cout << ((ans%mod)+mod)%mod << endl;



    return 0;
}