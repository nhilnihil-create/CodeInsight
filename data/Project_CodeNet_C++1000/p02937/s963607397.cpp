#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    string s, t; cin >> s >> t;

    vector<vector<ll>> ma(26);
    for (ll i = 0; i < (ll)s.length(); ++i) {
        ll u = s[i] - 'a';
        ma[u].push_back(i + 1);
    }

    ll ans = 0;
    ll cnt = 0;
    for (ll i = 0; i < (ll)t.length(); ++i) {
        ll u = t[i] - 'a';

        if (ma[u].empty()) {
            cout << -1 << endl;
            return 0;
        }

        bool match = false;
        auto it = upper_bound(ma[u].begin(), ma[u].end(), cnt);
        if (it != ma[u].end()) {
            ll id = distance(ma[u].begin(), it);
            ans += ma[u][id] - cnt;
            match = true;
            cnt = ma[u][id];
        }

        if (!match) {
            ans += s.length() - cnt;
            ans += ma[u][0];
            cnt = ma[u][0];
        }
    }

    cout << ans << endl;
}