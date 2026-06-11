#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;
using ll = long long;

ll dp[3001][3001];

int main()
{
    ll N, S;
    array<ll, 3001> A;

    cin >> N >> S;
    for (ll i = 1; i <= N; i++) cin >> A[i];

    dp[0][0] = 1;
    for (ll j = 1; j <= S; j++) dp[0][j] = 0;

    for (ll i = 1; i <= N; i++) for (ll j = 0; j <= S; j++)
    {
        dp[i][j] = 0;
        dp[i][j] += 2 * dp[i - 1][j];
        if (j >= A[i]) dp[i][j] += dp[i - 1][j - A[i]];
        dp[i][j] %= 998244353;
    }

    cout << dp[N][S] << endl;
}