#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5, mod = 1e9 + 7;
string s;
int dp[N][5];

int solve(int i, int pre)
{
    if (i == s.size())
        return 0;
    if (dp[i][pre] != -1)
        return dp[i][pre];
    int ans = 0;
    if (i == 0)
    {
        for (int j = 1; j < 4; j++)
            ans = max(ans, solve(i + j, j) + 1);
    }
    else
    {
        string t;
        int j = i - pre;
        while (j < i)
            t += s[j++];
        for (j = 1; j < 4 && j + i <= s.size(); j++)
        {
            if (j != pre)
                ans = max(ans, solve(i + j, j) + 1);
            else
            {
                string l;
                int k = i;
                while (k < i + j)
                    l += s[k++];
                if (t != l)
                    ans = max(ans, solve(i + j, j) + 1);
            }
        }
    }
    return dp[i][pre] = ans;
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    cin >> s;
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0);
    return 0;
}