#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
using P  = pair<int,int>;
const int INF = 1001001001;
const int MOD = 1000000007;

ll modpow(ll a, ll n, ll mod = MOD) {
    
    ll rtn = 1;
    a %= MOD;
    while (n) {
        if (n & 1) rtn *= a;
        a *= a;
        rtn %= mod;
        a   %= mod;
        n >>= 1;
    }
    return rtn;
}


int main(){
    ll n;
    cin >> n;
    
    ll ans = modpow(10,n,MOD) + modpow(8,n,MOD) + 2*MOD - 2*modpow(9,n,MOD);
    ans %= MOD;
    
    cout << ans << endl;
    
    return 0;
}