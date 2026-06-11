#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<ll, ll> mp;
    rep(i, n) {
        cin >> a[i];
        mp[a[i]]++;
    }

    ll ans = 0;
    for (auto &p : mp) {
        ans += p.second * (p.second - 1) / 2;
    }

    rep(i, n) {
        int now = mp[a[i]];
        cout << ans - now + 1 << "\n";
    }

    return 0;
}