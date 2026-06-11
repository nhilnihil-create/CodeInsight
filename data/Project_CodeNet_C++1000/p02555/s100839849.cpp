#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
long long dp[2010];
int main()
{
    int S;
    cin >> S;
    dp[0] = 1LL;
    dp[1] = 0LL;
    dp[2] = 0LL;
    for (int i = 3; i <= S; i++)
    {
        dp[i] = (dp[i - 3] + dp[i - 1]) % mod;
    }
    cout << dp[S] << endl;
}