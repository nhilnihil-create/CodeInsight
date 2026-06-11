#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll mod = 1000000007;

ll modpow(ll a,ll n){
    ll res = 1;
    while(n>0){
        if(n&1)res = res * a % mod;
        a = a*a%mod;
        n>>=1; 
    }
    return res;
}

ll choose(ll n,ll b){
    ll x = 1,y = 1;
    rep(i,b){
        x *= n-i; x %= mod;
        y *= i+1; y %= mod;
    }
    return x * modpow(y,mod-2) % mod;
}

int main(){
    ll n,a,b;
    ll ans;
    cin >> n >> a >> b;
    ans = modpow(2,n);
    ans -= 1;
    ans -= choose(n,a);
    ans -= choose(n,b);
    while(ans < 0) ans += mod;
    cout << ans << endl;
}