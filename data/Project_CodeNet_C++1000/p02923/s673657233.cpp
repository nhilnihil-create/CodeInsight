#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    ll n;
    cin >> n;
    vector<ll>h(n);
    ll ans = 0;
    rep(i, n) cin >> h[i];
    ll c  = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (h[i] >= h[i+1]) {
            c++;
            ans = max(ans, c);
        }else {
            c = 1;
        }
    }
    if (ans == 0) {
        ans = 1;
    }
    cout << ans - 1 << endl;
    return 0;
}
