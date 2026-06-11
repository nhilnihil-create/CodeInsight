#include <iostream>
#include <vector>
using namespace std;
int n, s, a[3000];
const long m = 998244353;
int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int64_t> dp(s + 1);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = s; j >= 0; j--)
        {
            dp[j] += dp[j];
            if (j >= a[i])
            {
                dp[j] += dp[j - a[i]];
            }
            if (j == a[i])
            {
                ++dp[j];
            }
            if (j == 0)
            {
                ++dp[j];
            }
            if (dp[j] >= m)
            {
                dp[j] %= m;
            }
        }
    }
    cout << dp[s] << endl;
}