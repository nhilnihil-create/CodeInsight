#include <bits/stdc++.h>
using namespace std;

bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}

int dp[100001];

int main()
{
    dp[100] = 1;
    dp[101]=1;
    dp[102]=1;
    dp[103] = 1;
    dp[104] = 1;
    dp[105] = 1;
    for (size_t i = 106; i <= 100000; i++)
    {
        dp[i] = (dp[i - 100] | dp[i - 101] | dp[i - 102] | dp[i - 103] | dp[i - 104] | dp[i - 105]);
        /* code */
    }
    int x;
    cin>>x;
    cout << dp[x] << endl;
    return 0;
}