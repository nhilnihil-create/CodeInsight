#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int k, q;
    cin >> k >> q;
    int d[k];
    rep(i, k) {
        cin >> d[i];
    }
    int n[q], x[q], m[q];
    rep(i, q) {
        cin >> n[i] >> x[i] >> m[i];
    }
    rep(i, q) {
        int t[k];
        rep(j, k) {
            t[j] = d[j] % m[i];
        }
        ll sum[k + 1] = {};
        int cnt[k + 1] = {};
        rep(j, k) {
            sum[j + 1] = sum[j] + t[j];
            cnt[j + 1] = cnt[j] + (t[j] == 0);
        }
        n[i]--;
        cout << n[i] - (n[i] / k * cnt[k] + cnt[n[i] % k]) -
                    (x[i] % m[i] + n[i] / k * sum[k] + sum[n[i] % k]) / m[i]
             << endl;
    }
    return 0;
}