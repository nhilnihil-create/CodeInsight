#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W;
    cin >> H >> W;
    vector<vector<int>> board(H+1,vector<int>(W+1));
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            char c;
            cin >> c;
            if (c == '#') board[i][j] = 1;
        }
    }
    vector<vector<int>> dp(H+5,vector<int>(W+5,INF));
    if (board[0][0] == 1){
        dp[0][0] = 1;
    } else {
        dp[0][0] = 0;
    }
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            if (board[i+1][j] == 1 && board[i][j] == 0) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            } else {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            }
            if (board[i][j+1] == 1 && board[i][j] == 0) {
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
            }else {
                dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
            }
        }
    }
    cout << dp[H-1][W-1] << "\n";
}