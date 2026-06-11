#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF (1 << 30)
using namespace std;

int editdistance(string a, string b)
{
    int dp[a.size() + 1][b.size() + 1];
    rep(i, a.size() + 1) rep(j, b.size() + 1)
    {
        dp[i][j] = INF;
    }
    rep(i, a.size() + 1) dp[i][0] = i;
    rep(j, b.size() + 1) dp[0][j] = j;
    for (int i = 1; i < a.size() + 1; i++)
        for (int j = 1; j < b.size() + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            dp[i][j] = min({dp[i][j], dp[i][j - 1] + 1, dp[i - 1][j] + 1});
        }
    return dp[a.size()][b.size()];
}

int main()
{

    string s1, s2;
    cin >> s1 >> s2;
    cout << editdistance(s1, s2) << endl;
    return 0;
}

