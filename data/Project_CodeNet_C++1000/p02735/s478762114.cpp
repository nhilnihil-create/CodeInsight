#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)

int H, W;
string S[120];
int dp[110][110];

signed main()
{
    cin >> H >> W;
    rep(i, H)cin >> S[i];

    rep(i, H)rep(j, W)
    {
        if(i == 0 && j == 0)continue;
        dp[i][j] = 10000;

        if(i)dp[i][j] = min(dp[i][j], dp[i - 1][j] + (S[i - 1][j] != S[i][j]));
        if(j)dp[i][j] = min(dp[i][j], dp[i][j - 1] + (S[i][j - 1] != S[i][j]));
    }

    int ans = 0;
    if(dp[H - 1][W - 1] % 2)
        cout << dp[H - 1][W - 1] / 2 + 1 << endl;
    else
        cout << dp[H - 1][W - 1] / 2 + (S[0][0] == '#') << endl;

    return 0;
}
