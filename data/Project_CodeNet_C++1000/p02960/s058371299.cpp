#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAX { 100010 }, MAXR { 15 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

ll dp[MAX][MAXR];

ll solve(const string& s)
{
    auto N = s.size();

    dp[0][0] = 1;

    for (size_t i = 0; i < N; ++i)
    {
        int a = 0, b = 9;

        if (s[i] != '?')
        {
            auto d = s[i] - '0';

            a = b = d;
        }

        for (auto d = a; d <= b; ++d)
        {
            for (int r = 0; r < 13; ++r)
            {
                auto t = (10*r + d) % 13;

                dp[i + 1][t] = (dp[i + 1][t] + dp[i][r]) % MOD;
            }
        }
    }

    return dp[N][5];
}

int main()
{
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    auto ans = solve(s);

    cout << ans << '\n';

    return 0;
}
