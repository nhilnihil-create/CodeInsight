#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    vector<ll> b(n);
    rep(i,n+1) cin >> a[i];
    rep(i,n) cin >> b[i];
    ll ans = 0, t = 0;
    rep(i,n) {
        ll m = min(a[i]-t, b[i]);
        ans += m+t;
        t = min(a[i+1], b[i]-m);
    }
    ans += min(a[n], t);
    cout << ans << endl;
    return 0;
}