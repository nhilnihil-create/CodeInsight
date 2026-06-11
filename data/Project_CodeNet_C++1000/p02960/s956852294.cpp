#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 0; i < n; ++i)

constexpr ll mod = 1e9 + 7;

int getDig(char ch)
{
    return atoi(&ch);
}

int main()
{
    std::string s;

    std::cin >> s;

    std::reverse(std::begin(s), std::end(s));

    std::vector<std::vector<ll>> dp(s.size(), std::vector<ll>(13));

    if (s[0] == '?')
    {
        rep(i, 10)
        {
            dp[0][i] = 1;
        }
    }
    else
    {
        dp[0][getDig(s[0])] = 1;
    }

    int x = 10;

    for (int i = 1; i < s.size(); ++i)
    {
        for (int j = 0; j < 13; ++j)
        {
            if (s[i] == '?')
            {
                for (int k = 0; k < 10; ++k)
                {
                    int prev = (j - k * x + 117) % 13;
                    dp[i][j] += dp[i - 1][prev];
                }
                dp[i][j] %= mod;
            }
            else
            {
                int prev = (j - getDig(s[i]) * x + 117) % 13;

                dp[i][j] = dp[i - 1][prev];
            }
        }
        x = x * 10 % 13;
    }

    //std::cerr << "DEBUG:" << s << std::endl;

    std::cout << dp[s.size() - 1][5] << std ::endl;

    return 0;
}