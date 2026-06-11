#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    map<ll, ll> l, r;

    rep(i, n) {
        ++l[i + a[i]];
        ++r[i - a[i]];
    }

    ll ans = 0;
    for (auto &p : l) {
        ans += p.second * r[p.first];
    }

    cout << ans << endl;

    return 0;
}