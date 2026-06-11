#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
const int MOD = 1e9 + 7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    ll p = 1;
    rep(i, 60){
        ll x = 0, y =0;
        rep(j, n){
            if (a[j]%2 == 0) {
                x++;
            }else {
                y++;
            }
            a[j] = a[j] >> 1;
        }
        ans += (x*y)%MOD*p%MOD;
        ans = ans%MOD;
        p *= 2;
        p %= MOD;
    }
    cout << ans << endl;
    return 0;
}
