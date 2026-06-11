#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
const int MOD  = 2019;
int main() {
    ll l, r, ans;
    cin >> l >> r;
    ans = 3000;
    if ((r - l)>=2019) {
        ans = 0;
    }else{
        for (ll i = l; i < r; i++) {
            for (ll j = i + 1; j <= r; j++) {
                ans = min(ans, (i*j)%MOD);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
