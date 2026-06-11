#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    ll ans = 0;
    rep(i,n) {
        ll t = 0;
        for(ll j = i+1; j < n; j++) {
            if (h[j-1] < h[j]) break;
            ++t;
        }
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}
