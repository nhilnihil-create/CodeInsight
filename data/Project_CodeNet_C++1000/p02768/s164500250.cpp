#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
#define BMAX 200000

const int MOD =1000000007;
ll inv[200005];

void inv_init(){
    inv[1]=1LL;
    for(int i=2; i<=BMAX; i++){
        inv[i] = MOD - (MOD/i) * inv[MOD%i] % MOD;
    }
    return;
}

ll combi(ll n, ll a){
    if(n<a)return 0LL;
    if(n<0 || a<0)return 0LL;
    
    ll rtn = 1;
    for(int i=0; i<a; i++){
        rtn *= n-i;
        rtn %= MOD;
        rtn *= inv[i+1];
        rtn %= MOD;
    }
    return rtn;
}

ll powmod(ll a, ll n, ll mod = MOD) {
    ll rtn = 1;
    while (n > 0) {
        if (n & 1) rtn = rtn * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return rtn;
}


int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    inv_init();
    
    ll ans = powmod(2,n,MOD);
    ans += MOD - combi(n,a);
    ans += MOD - combi(n,b);
    ans += MOD - 1;
    ans %= MOD;
    
    cout << ans << endl;
}