#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

template <typename T1, typename T2>
inline void chmin(T1& a, T2 b) {
    if (a > b) a = b;
}

template <typename T>
vector<T> compress(vector<T> vec) {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}

template <typename T>
map<T, int> dict(vector<T>& vec) {
    map<T, int> res;
    for (int i = 0; i < (int)vec.size(); i++) {
        res[vec[i]] = i;
    }
    return res;
}

signed main() {
    int n, K;
    cin >> n >> K;
    vector<ll> h(n);
    rep(i, n) {
        cin >> h[i];
    }
    h.emplace_back(0);
    auto c = compress(h);
    auto d = dict(c);
    int m = d.size();
    ll dp[n + 1][m + 1][K + 1];
    fill(dp[0][0], dp[n + 1][0], LINF);
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k <= K; k++) {
                if (k < K) chmin(dp[i + 1][j][k + 1], dp[i][j][k]);
                chmin(dp[i + 1][d[h[i]]][k],
                      dp[i][j][k] + max(0LL, h[i] - c[j]));
            }
        }
    }
    ll ans = LINF;
    for (int j = 0; j < m; j++) {
        for (int k = 0; k <= K; k++) {
            chmin(ans, dp[n][j][k]);
        }
    }
    cout << ans << endl;
    return 0;
}