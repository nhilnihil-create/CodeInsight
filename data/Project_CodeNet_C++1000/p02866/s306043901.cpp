#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


const ll mod = 998244353;

ll power(ll b, ll x) {
    ll ans = 1;
    for (int i = 0; i < x; i++) {
        ans *= b;
        ans %= mod;
    }

    return ans;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> d(n);
    rep(i, n) cin >> d[i];
    if (d[0] != 0) {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i < n; i++) {
        if (d[i] == 0) {
            cout << 0 << endl;
            return;
        }
    }

    map<ll, ll> num_dist;
    for (int i = 1; i < n; i++) {
        num_dist[d[i]]++;
    }

    int ok = 1;
    for (int i = 1; i < n; i++) {
        if (num_dist[i] == 0) {
            ok = 0;
        }
        if (ok == 0 && num_dist[i] != 0) {
            cout << 0 << endl;
            return;
        }
    }

    ll ans = 1;
    for (int i = 2; i < n; i++) {
        ans *= power(num_dist[i-1], num_dist[i]);
        ans %= mod;
    }

    cout << ans << endl;

}

int main() {
    solve();
    return 0;
}
