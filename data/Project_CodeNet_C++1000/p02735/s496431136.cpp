#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

ll mod = 1000000007;

signed main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> vvi;
    vector<vector<int>> dp(h, vector<int>(w, 0));
    rep(i, h)
    {
        string s;
        cin >> s;
        vi a(w);
        rep(j, s.size())
        {

            if (s[j] == '#')
            {
                a[j] = 1;
            }
            else
            {
                a[j] = 0;
            }
        }
        vvi.push_back(a);
    }
    rep(i, h)
    {
        rep(j, w)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    dp[i][j] = vvi[i][j];
                }
                else
                {
                    if (vvi[i][j] == 1)
                    {
                        if (vvi[i][j - 1] == 0)
                        {
                            dp[i][j] = dp[i][j - 1] + 1;
                        }
                        else
                        {
                            dp[i][j] = dp[i][j - 1];
                        }
                    }
                    else
                    {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
            }
            else
            {
                if (j == 0)
                {
                    if (vvi[i - 1][j] == 0 && vvi[i][j] == 1)
                    {
                        dp[i][j] = dp[i - 1][j] + 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
                else
                {
                    if (vvi[i][j] == 1)
                    {
                        if (vvi[i - 1][j] == 0 && vvi[i][j - 1] == 1)
                        {
                            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1]);
                        }
                        else if (vvi[i - 1][j] == 1 && vvi[i][j - 1] == 0)
                        {
                            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1] + 1);
                        }
                        else if (vvi[i - 1][j] == 1 && vvi[i][j - 1] == 1)
                        {
                            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                        }
                        else if (vvi[i - 1][j] == 0 && vvi[i][j - 1] == 0)
                        {
                            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                        }
                    }
                    else
                    {
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
        }
    }
    // rep(i, h)
    // {
    //     rep(j, w)
    //     {
    //         printf("%3d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    cout << dp[h - 1][w - 1] << endl;
    return 0;
}