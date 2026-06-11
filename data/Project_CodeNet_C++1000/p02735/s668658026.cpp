#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll H, W;

char c[110][110];
ll dp[110][110];

int main() {
    cin >> H >> W;
    rep(i, H)rep(j, W) cin >> c[i][j];

    rep(i, H)rep(j, W) dp[i][j] = INF;

    if (c[0][0] == '#') {
        dp[0][0] = 1; 
    } else {
        dp[0][0] = 0;
    }

    rep(i, H)rep(j, W) {
        // 右の遷移
        dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + (c[i][j] == '.' && c[i][j + 1] == '#' ? 1 : 0));

        // 下の遷移
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (c[i][j] == '.' && c[i + 1][j] == '#' ? 1 : 0));
    }

    cout << dp[H - 1][W - 1] << endl;
}