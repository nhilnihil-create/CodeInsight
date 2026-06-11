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

    map<ll, ll> mp;
    rep(i, n) {
        ++mp[i + a[i]];
    }

    ll ans = 0;
    rep(i, n) {
        ans += mp[i - a[i]];
    }

    cout << ans << endl;

    return 0;
}