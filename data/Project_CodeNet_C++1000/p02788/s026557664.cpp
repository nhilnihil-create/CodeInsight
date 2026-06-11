#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second

void solve() {
    int n, d, a;
    cin >> n >> d >> a;
    vector<pll> X(n);
    rep(i, n) {
        ll x, h;
        cin >> x >> h;
        X[i] = {x, h};
    }
    sort(all(X));
    queue<pll> que;
    ll acc = 0;
    ll ans = 0;
    rep(i, n) {
        while(que.size() && X[i].fi > que.front().fi) {
            acc -= que.front().se;
            que.pop();
        }
        X[i].se -= acc * a;
        ll damage = max(0LL, (X[i].se + a - 1) / a);
        acc += damage;
        ans += damage;
        que.push({X[i].fi + 2 * d, damage});
    }
    cout << ans << endl;
    return ;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
