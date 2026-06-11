#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    ll a[n], b[n];
    rep(i, n) {
        cin >> a[i];
    }
    using P = pair<ll, int>;
    priority_queue<P> que;
    rep(i, n) {
        cin >> b[i];
        que.emplace(b[i], i);
    }
    ll ans = 0;
    while (!que.empty()) {
        P p = que.top();
        int t = p.second;
        que.pop();
        if (a[t] > p.first) {
            cout << -1 << endl;
            return 0;
        }
        if (a[t] < b[t]) {
            ll sum = b[(t - 1 + n) % n] + b[(t + 1) % n];
            if (b[t] - a[t] < sum) {
                cout << -1 << endl;
                return 0;
            }
            ans += (b[t] - a[t]) / sum;
            b[t] -= sum * ((b[t] - a[t]) / sum);
            que.emplace(b[t], t);
        }
    }
    cout << ans << endl;
    return 0;
}