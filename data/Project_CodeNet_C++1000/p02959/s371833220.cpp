#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n+1), b(n+1, 0);
    rep(i, n + 1) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll ans = 0;
    ll c;
//    rep(i, n + 1) cout << a[i] << "%";
//    rep(i, n + 1) cout << b[i] << "&";
    for (ll i = n;  i >= 1; i--) {
        c = min(b[i], a[i]);
//        cout << c <<',';
        ans += c;
        b[i] -= c;
        a[i] -= c;
        c = min(b[i - 1], a[i]);
//        cout << b[i - 1] << "&" << a[i] << " ";
//        cout << c <<',';
        ans += c;
        b[i - 1] -= c;
        a[i] -= c;
    }
    c = min(b[0], a[0]);
//    cout << c <<',';
    ans += c;
    b[0] -= c;
    a[0] -= c;
    cout << ans << endl;
    return 0;
}
