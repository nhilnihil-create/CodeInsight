#include <iostream>
#include <vector>

constexpr int MOD = 1000000007;

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 3)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 0;


    for (int i = 3; i < n + 1; i++)
    {
        int s = 0;
        for (int j = 3; j <= i; j++)
            s = (s + dp[i - j]) % MOD;
        dp[i] = s;
    }


    cout << dp[n] << endl;
}