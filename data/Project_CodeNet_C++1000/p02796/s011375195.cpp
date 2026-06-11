#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void solve() {
    int n;
    cin >> n;
    vector<pair<ll,ll>> robot(n);
    rep(i, n) {
        ll x, l;
        cin >> x >> l;
        // robot[i] = {x - l, x + l};
        // robot[i] = {l, x};
        robot[i] = {x + l, x - l};
    }

    sort(robot.begin(), robot.end());
    int ans = 0;
    ll r = -((ll)1e9 + 7);
    rep(i, n) {
        if (r <= robot[i].second) {
            ans++;
            r = robot[i].first;
        }
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
