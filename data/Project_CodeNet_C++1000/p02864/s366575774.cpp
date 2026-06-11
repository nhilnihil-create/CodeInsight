#include <bits/stdc++.h>
using namespace std;
#define INF_LL 1LL << 40
#define INF 1 << 31
#define MOD 1000000007
#define ll long long
#define all(x) x.begin(), x.end()
#define REP(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
#define prique priority_queue
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<P> vp;
typedef vector<ll> vl;
typedef vector<vector<int>> matrix;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int sign[2] = {1, -1};
template <class T> bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
struct edge {
    int to, cost;
};

ll dp[301][301][301]; // そこまでのコスト

int main() {
    rep(i, 301) rep(j, 301) rep(k, 301) dp[i][j][k] = INF_LL;
    dp[0][0][0] = 0;
    int n, a;
    cin >> n >> a;
    vi h(n + 1, 0);
    rep(i, n) cin >> h[i + 1];
    rep(i, n) rep(j, i + 2) rep(k, i + 1) {
        if(dp[i][j][k] == INF_LL) {
            continue;
        }
        chmin(dp[i + 1][j + 1][k], dp[i][j][k]);
        chmin(dp[i + 1][j][i + 1], dp[i][j][k] + max(0, h[i + 1] - h[k]));
    }
    // rep(i, n + 1) {
    //     rep(j, i + 1) {
    //         rep(k, i + 1) cout << (dp[i][j][k] == INF_LL ? -1 : dp[i][j][k])
    //                            << " ";
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    ll ans = INF_LL;
    rep(j, n + 1) chmin(ans, dp[n][a][j]);
    cout << ans << endl;
}
