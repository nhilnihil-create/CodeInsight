#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1 << 30;

template<class T> inline bool chmin(T &a, T b)
{
    if(a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int H, W;
    cin >> H >> W;
    vector<string> mp(H);
    for(int i=0; i<H; i++) cin >> mp.at(i);

    vector<vector<int>> dp(H, vector<int>(W,  INF));
    dp[0][0] = (mp[0][0] == '#' ? 1 : 0);
    for(int i=0; i<H; i++)
    {
        for(int j=0; j<W; j++)
        {
            if(i>0) chmin(dp[i][j], dp[i-1][j] + ((mp[i][j]=='#' && mp[i-1][j]=='.') ? 1 : 0));
            if(j>0) chmin(dp[i][j], dp[i][j-1] + ((mp[i][j]=='#' && mp[i][j-1]=='.') ? 1 : 0));
        }
    }
    cout << dp[H-1][W-1] << endl;

    return 0;
}
