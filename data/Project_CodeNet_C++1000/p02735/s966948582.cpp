#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
const int INF = 1e18, MOD = 1e9 + 7;
int h, w;
int dp[111][111] = {};
string board[111];

signed main() {
    cin>>h>>w;
    for (int i = 0; i < h; i++) {
        cin>>board[i];
    }
    dp[0][0] = board[0][0] == '#';
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == j && j == 0) continue;
            if (i == 0) {
                dp[i][j] = dp[i][j - 1] + (board[i][j - 1] == '.' && board[i][j] == '#');
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + (board[i - 1][j] == '.' && board[i][j] == '#');
            } else {
                dp[i][j] = min(
                    dp[i][j - 1] + (board[i][j - 1] == '.' && board[i][j] == '#'),
                    dp[i - 1][j] + (board[i - 1][j] == '.' && board[i][j] == '#')
                );
            }
        }
    }
    cout<<dp[h - 1][w - 1]<<endl;
}