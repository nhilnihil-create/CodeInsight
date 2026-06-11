#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    int ans = 0;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        for (int j = s.size() - 1; j > i; --j)
        {
            if (s[i] == s[j])
            {
                dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 1);
                ans = max(ans,
                          min(dp[i][j], j - i));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
