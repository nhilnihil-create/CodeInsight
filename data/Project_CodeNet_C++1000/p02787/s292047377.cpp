#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
using namespace std;

int main()
{
    //入力
    int h, n;
    cin >> h >> n;
    vector<int>a(n);
    vector<int>b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    //DP[i-1][d]はi番目までのスキルでｄダメージを与えるときの最小マナ。０で初期化している
    vector<vector<int>> dp(n + 1, vector<int>(h + 100100));
    for (int i = 0; i < h + 100100; i++)
    {
        if (i % a[0] == 0)
        {
            dp[0][i] = (i / a[0]) * b[0];
        }
        else
        {
            dp[0][i] = (((i - i % a[0]) / a[0]) + 1) * b[0];
        }
    }

    //漸化式
    for (int i = 0; i < n; i++)
    {
        for (int d = 0; d <= h+100000; d++)
        {
            dp[i + 1][d] = dp[i][d];
            if (a[i] <= d)
            {
                dp[i + 1][d] = min(dp[i][d], dp[i + 1][d - a[i]] + b[i]);
            }
        }
    }
    int ans = 100000000;
    for (int i = h; i < h + 100000; i++)
    {
        if (ans > dp[n][i])
        {
            ans = dp[n][i];
        }
    }

    cout << ans<< "\n";

    return 0;
}