#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int m;
    cin >> m;
    ll sum[2] = {};
    int d;
    ll c;
    rep(i, m) {
        cin >> d >> c;
        sum[0] += c;
        sum[1] += c * d;
    }
    cout << sum[0] - 1 + (sum[1] - 1) / 9 << endl;
    return 0;
}