#include <bits/stdc++.h>

using namespace std;


int main() {
    int H, W;
    cin >> H >> W;
    int dp[101][101];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            dp[i][j] = 1e9;
        }
    }
    char c[101][101];
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> c[i][j];
    dp[0][0] = c[0][0] == '#';
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + (c[i][j] != c[i - 1][j]));
            if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1] + (c[i][j] != c[i][j - 1]));
        }
    }
    cout << (dp[H - 1][W - 1] + 1) / 2 << endl;
}
