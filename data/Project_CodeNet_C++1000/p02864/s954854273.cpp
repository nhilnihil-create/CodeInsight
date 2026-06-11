#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define iter(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define riter(i, c) for (auto i = (c).rbegin(); i != (c).rend(); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

ll dp[303][303];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    vector<ll> H(N + 1);
    H[0] = 0;
    rep(i, 1, N + 1) cin >> H[i];
    rep(i, 0, N + 1) rep(j, 0, N + 1) {
        dp[i][j] = INF;
    }
    dp[0][0] = 0;
    rep(i, 1, N + 1) rep(j, 1, N + 1) {
        rep(k, 0, i) {
            dp[i][j] = min(dp[i][j], dp[k][j - 1] + max(0LL, H[i] - H[k]));
        }
    }
    ll ans = INF;
    rep(i, 0, N + 1) {
        ans = min(ans, dp[i][N - K]);
    }
    cout << ans << endl;
    return 0;
}