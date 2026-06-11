#include <bits/stdc++.h>
using namespace std;
 
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;
 
const int MOD = 1e9+7;
 
ll modpower(ll x, ll y) {
    ll res = 1;
    x %= MOD;
    if(!x) return 0;
    while(y) {
        if(y&1) res = (res*x)%MOD;
        x = (x*x)%MOD;
        y >>= 1;
    }
    return res;
}
 
int main() {
    FASTIO
 
    ll n;
    cin >> n;
    ll ans = modpower(10,n) - 2*modpower(9,n) + modpower(8,n);
    if(ans < 0) ans += 2*MOD;
    ans %= MOD;
    cout << ans << "\n";
    
    return 0;
}