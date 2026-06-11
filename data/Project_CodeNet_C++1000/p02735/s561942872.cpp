#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> G(H, vector<char>(W));

    rep(i, H) {
        rep(j, W) { cin >> G[i][j]; }
    }

    vector<vector<int>> dp(H + 5, vector<int>(W + 5, 1e9));
    dp[0][0] = 0;
    if (G[0][0] == '#')
        dp[0][0] = 1;

    int dx[2] = {1, 0};
    int dy[2] = {0, 1};
    rep(i, H) {
        rep(j, W) {
            for (int k = 0; k < 2; k++) {
                int nx = j + dx[k];
                int ny = i + dy[k];
                if (nx >= W || ny >= H)
                    continue;
                if (G[i][j] == '.' && G[ny][nx] == '#')
                    dp[ny][nx] = min(dp[ny][nx], dp[i][j] + 1);
                else
                    dp[ny][nx] = min(dp[ny][nx], dp[i][j]);
            }
        }
    }

    cout << dp[H - 1][W - 1] << endl;
}