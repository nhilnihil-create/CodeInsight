#include <bits/stdc++.h>
using namespace std;

const int inf = 1e5;
int dp[101][101];

signed main () {
    int h, w;
    cin >> h >> w;
    vector < string > s(h);
    for (int i = 0; i < h; ++i) 
        cin >> s[i];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i + j == 0) 
                dp[i][j] = int(s[i][j] == '#');
            else {
                dp[i][j] = inf;
                if (i)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + int(s[i - 1][j] == '.' && s[i][j] == '#'));
                if (j)
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + int(s[i][j - 1] == '.' && s[i][j] == '#'));
            }
        }
    }
    cout << dp[h - 1][w - 1] << '\n';
}
