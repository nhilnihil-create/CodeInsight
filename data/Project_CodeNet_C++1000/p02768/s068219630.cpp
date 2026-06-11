#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
using P = pair<int,int>;
typedef long long ll;


#define rep(i,n) for (int i=0; i<(n); i++)
const int INF =1001001001;
const ll BIG = 1000000007;
const double PI = 3.141592653589793;

ll modpow(ll a, ll b, ll mod = 1000000007) {
    ll res = 1;
    for(a %= mod; b; a = a * a % mod, b>>=1) if(b&1) res = res*a%mod;
    return res;
}

ll combination_nCa(ll n, ll r, ll mod=1000000007){
    ll x = 1, y = 1;
    rep(i,r){
        x = (x*(n-i))%mod;
        y = (y*(i+1))%mod;
    }
    return (x*modpow(y, mod-2))%mod;
}

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = (modpow(2, n) - 1 - combination_nCa(n, a) - combination_nCa(n, b))%BIG;
    if(ans<0) ans += BIG;
    cout << ans << endl;
    return 0;
}