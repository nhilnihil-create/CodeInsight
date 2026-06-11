#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<vector<char>> G(H, vector<char>(W));
    vector<vector<ll>> dp(H + 1, vector<ll>(W + 1, INF));

    rep(i, H) {
        rep(j, W) { cin >> G[i][j]; }
    }

    if (G[0][0] == '#')
        dp[0][0] = 1;
    else
        dp[0][0] = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i - 1 >= 0 && G[i - 1][j] == '.' && G[i][j] == '#')
                chmin(dp[i][j], dp[i - 1][j] + 1);
            if (j - 1 >= 0 && G[i][j - 1] == '.' && G[i][j] == '#')
                chmin(dp[i][j], dp[i][j - 1] + 1);
            if (i - 1 >= 0 && G[i - 1][j] == '.' && G[i][j] == '.')
                chmin(dp[i][j], dp[i - 1][j]);
            if (j - 1 >= 0 && G[i][j - 1] == '.' && G[i][j] == '.')
                chmin(dp[i][j], dp[i][j - 1]);
            if (i - 1 >= 0 && G[i - 1][j] == '#' && G[i][j] == '.')
                chmin(dp[i][j], dp[i - 1][j]);
            if (j - 1 >= 0 && G[i][j - 1] == '#' && G[i][j] == '.')
                chmin(dp[i][j], dp[i][j - 1]);
            if (i - 1 >= 0 && G[i - 1][j] == '#' && G[i][j] == '#')
                chmin(dp[i][j], dp[i - 1][j]);
            if (j - 1 >= 0 && G[i][j - 1] == '#' && G[i][j] == '#')
                chmin(dp[i][j], dp[i][j - 1]);
        }
    }

    cout << dp[H - 1][W - 1] << endl;
}