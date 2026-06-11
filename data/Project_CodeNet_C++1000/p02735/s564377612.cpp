#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h, w;
    cin >> h >> w;
    string s[h + 1];
    for (int i = 0; i < h; i++) {
        cin >> s[i];
        s[i] += 'X';
    }
    
    vector<vector<int>> dp(h + 1, vector<int>(w + 1, 1e9));
    dp[0][0] = (s[0][0] == '#');
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (s[i][j] == '.' && s[i + 1][j] == '#'));
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + (s[i][j] == '.' && s[i][j + 1] == '#'));
        }
    }

    cout << dp[h - 1][w - 1] << '\n';
    return 0;
}