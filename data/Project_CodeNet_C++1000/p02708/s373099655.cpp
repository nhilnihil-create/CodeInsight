#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll MOD = (ll)1e9 + 7;

ll n, k;
vector<ll> v;
void solve() {
    cin >> n >> k;
    v.push_back(0);
    for (ll i = 1; i <= n; i++) {
        v.push_back(v[i-1] + i);
    }

    ll ans = 1;
    for (int i = k; i <= n; i++) {
        ll mi = v[i-1];
        ll mx = v[n] - v[n-i];
        ans += mx - mi + 1;
        ans %= MOD;
        // cout << mi << " " << mx << " " << ans << endl;
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
