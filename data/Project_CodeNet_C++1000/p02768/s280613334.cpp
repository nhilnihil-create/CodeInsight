#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n); i > 0; i--)
#define all(n) n.begin(), n.end()
#define print(n) cout << n << endl
ll mods = 1000000007;

ll modpow(ll k, ll n){
    ll ans = 1;
    while(n>0){
        if(n&1) ans = (ans * k) % mods;
        k = (k * k) % mods;
        n >>= 1;
    }
    return ans;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n,a,b;
    cin >> n >> a >> b;
    ll ans=modpow(2,n)-1,u=1,d=1;
    
    rep(i,max(a,b)){
        u = (u * (n-i)) % mods;
        d = (d * (i+1)) % mods;
        if(i==min(a,b)-1 || i==max(a,b)-1) ans = (ans-(u*modpow(d,mods-2))%mods+mods)%mods;
    }
    print(ans);
    return 0;
}