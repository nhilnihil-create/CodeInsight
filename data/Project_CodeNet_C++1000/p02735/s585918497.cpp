#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;



int main(){ 
    int H, W;
    cin >> H >> W;

    vector<vector<char>> s(H, vector<char>(W));

    rep(i,H) rep(j,W) {
        cin >> s[i][j];
    }

    vector<vector<int>> dp(H, vector<int>(W));

    if (s[0][0] == '#') dp[0][0] = 1;
    else dp[0][0] = 0;

    rep(i,H) rep(j,W) {
        if (i > 0 && j > 0) {
            int u, v;
            u = dp[i-1][j];
            v = dp[i][j-1];
            if (s[i-1][j] == '.' && s[i][j] == '#') u++;
            if (s[i][j-1] == '.' && s[i][j] == '#') v++;
            dp[i][j] = min(u,v);
        }
        if (i == 0 && j > 0) {
            dp[i][j] = dp[i][j-1];
            if (s[i][j-1] == '.' && s[i][j] == '#') dp[i][j]++;
        }
        if (i > 0 && j == 0) {
            dp[i][j] = dp[i-1][j];
            if (s[i-1][j] == '.' && s[i][j] == '#') dp[i][j]++;
        }
    }

    cout << dp[H-1][W-1] << endl;
   
    
}
