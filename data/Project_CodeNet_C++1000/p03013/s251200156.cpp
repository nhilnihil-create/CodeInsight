#include <bits/stdc++.h>

using namespace std;

int n, m, whi;
bool bro[100005];
int dp[100010];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i ++)
    {
        scanf("%d", &whi);
        bro[whi] = 1;
    }
    dp[0] = 1;
    for(int i = 0; i <= n; i ++)
    {
        //cout<<dp[i]<<' ';
        if(bro[i]) continue;
        dp[i + 1] += dp[i];
        dp[i + 1] %= 1000000007;
        dp[i + 2] += dp[i];
        dp[i + 2] %= 1000000007;
    }
    printf("%d", dp[n]);
    //system("pause");
    return 0;
}