#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ll x, y, a, b, c; cin >> x >> y >> a >> b >> c;
    vector<ll> p_(a), q_(b);
    for (ll i = 0; i < a; i++) {
        cin >> p_[i];
    }
    for (ll i = 0; i < b; i++) {
        cin >> q_[i];
    }
    vector<pair<ll, string>> pa;
    sort(p_.rbegin(), p_.rend());
    for (ll i = 0; i < x; i++) {
        pa.push_back({ p_[i], "red" });
    }
    sort(q_.rbegin(), q_.rend());
    for (ll i = 0; i < y; i++) {
        pa.push_back({ q_[i], "green" });
    }
    for (ll i = 0; i < c; i++) {
        ll r; cin >> r;
        pa.push_back({ r,"non" });
    }
    sort(pa.rbegin(), pa.rend());
    ll ans = 0;
    for (ll i = 0; i < x + y; i++) {        
            ans += pa[i].first;
    }
    cout << ans << endl;
    return 0;
}