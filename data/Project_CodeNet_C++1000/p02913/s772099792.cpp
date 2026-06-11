#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)

int n;
std::string s;

int dp[5010][5010];

int dfs(int i, int j)
{
    if (i >= n || j >= n || s[i] != s[j])
        return 0;
    if (dp[i][j] > 0)
        return dp[i][j];

    return dp[i][j] = std::min(dfs(i + 1, j + 1) + 1, j - i);
}

int main()
{
    std::cin >> n >> s;

    int ans = 0;

    rep(i, n)
    {
        rep(j, n)
        {
            if (j > i)
                ans = std::max(ans, dfs(i, j));
        }
    }

    std::cout << ans << std::endl;

    return 0;
}