#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int s;
    cin >> s;

    int dp[s + 1] = {0};

    dp[3] = 1;

    for (int i = 4; i <= s; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 3]) % MOD;
    }
    cout << dp[s] << '\n';
}