#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
    int h,w;
    cin >> h >> w;
    string s[h];
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
    }
    
    vector<vector<int>> dp(h, vector<int>(w, INT_MAX - 100));
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    dp[0][0] = (s[0][0] == '#');
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if(0 <= i + dy[k] && i + dy[k] < h && 0 <= j + dx[k] && j + dx[k] < w)
                {
                    if(s[i + dy[k]][j + dx[k]] == '#' && s[i][j] == '.')chmin(dp[i + dy[k]][j + dx[k]], dp[i][j] + 1);
                    else chmin(dp[i + dy[k]][j + dx[k]], dp[i][j]);
                }
            }
        }
    }
/*
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)cout << dp[i][j] << " ";
        cout << endl;
    }
*/
    cout << dp[h - 1][w - 1] << endl;
}