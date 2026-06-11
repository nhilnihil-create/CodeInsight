#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    s += '0';
    int n = s.size();
    vector<array<int, 2>> dp(n+1);
    dp[0][0] = 0, dp[0][1] = 1e9;
    for (int i = 0; i < n; ++i) {
        int u = s[i]-'0';
        dp[i+1][0] = min(dp[i][0]+u, (u == 9 ? (int)1e9 : dp[i][1]+u+1));
        dp[i+1][1] = min(dp[i][0]+10-u, dp[i][1]+9-u);
    }
    cout << dp[n][0] << '\n';
    return 0;
}
