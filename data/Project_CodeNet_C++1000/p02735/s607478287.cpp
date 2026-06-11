#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<bool>> mat(H, vector<bool>(W));
    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < W; j++) {
            mat[i][j] = s[j] == '#';
        }
    }
    vector<vector<int>> dp(H, vector<int>(W, 1e7));
    dp[0][0] = mat[0][0];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i > 0) {
                if (mat[i][j] && mat[i][j] != mat[i - 1][j])
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                else
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
            if (j > 0) {
                if (mat[i][j] && mat[i][j] != mat[i][j - 1])
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                else
                    dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[H - 1][W - 1] << endl;
}
