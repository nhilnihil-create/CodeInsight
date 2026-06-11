#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
double PI = 3.141592653589793;

int main()
{
    string S;
    cin >> S;
    int64_t L = S.size();
    reverse(S.begin(), S.end());
    vector<vector<int64_t>> dp(L, vector<int64_t>(13, 0));

    if (S[0] == '?')
        for (int64_t i = 0; i < 10; i++)
            dp[0][i] = 1;
    else
        dp[0][S[0] - '0'] = 1;

    int64_t keta = 10, x, y;
    char z;
    for (int64_t i = 1; i < L; i++)
    {
        char z = S[i];
        if (z == '?')
        {
            for (int x = 0; x < 10; x++)
            {
                for (int j = 0; j < 13; j++)
                {
                    y = (x * keta + j) % 13;
                    dp[i][y] += dp[i - 1][j];
                    dp[i][y] %= MOD;
                }
            }
        }
        else
        {
            x = z - '0';
            for (int j = 0; j < 13; j++)
            {
                y = (x * keta + j) % 13;
                dp[i][y] += dp[i - 1][j];
                dp[i][y] %= MOD;
            }
        }
        keta = (keta * 10) % 13;
    }
    cout << dp[L - 1][5];
}