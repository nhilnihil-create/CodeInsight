// AtCoder Beginner Contest 130 - Problem E: Common Subsequence (https://atcoder.jp/contests/abc130/tasks/abc130_e) 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX { 2010 };
const ll MOD { 1000000007 };

// dp[n][m] = # de subsequências comuns de xs[1..n] e ys[1..m]
ll dp[MAX][MAX];

ll solve(int N, int M, const vector<ll>& xs, const vector<ll>& ys)
{
    dp[0][0] = 1;

    for (int i = 1; i <= N; ++i)
        dp[i][0] = 1;

    for (int i = 1; i <= M; ++i)
        dp[0][i] = 1;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            // Princípio da Inclusão/Exclusão
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            dp[i][j] = (dp[i][j] - dp[i - 1][j - 1]) % MOD;
            dp[i][j] = (dp[i][j] + MOD) % MOD;

            // Se há a coincidência dos termos, gera-se novas subsequências que adicionam este termo
            if (xs[i] == ys[j])
            {
                dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] %= MOD;
            }

//            if (xs[i - 1] == ys[j])
//            {
 //               dp[i][j] += dp[i][j - 1];
  //              dp[i][j] %= MOD;
   //         }

 //           cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
        }
    }

    return dp[N][M];
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<ll> xs(N + 1), ys(M + 1);

    for (int i = 1; i <= N; ++i)
        cin >> xs[i];

    for (int i = 1; i <= M; ++i)
        cin >> ys[i];

    auto ans = solve(N, M, xs, ys);

    cout << ans << '\n';

    return 0;
}
