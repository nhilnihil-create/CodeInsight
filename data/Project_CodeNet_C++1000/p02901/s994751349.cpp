#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#include<cstring>
using namespace std;
int dp[1<<12];
int main()
{
    int n,m;
    cin >>n >>m;
    memset(dp,0x3f3f3f3f,sizeof(dp));
    dp[0] = 0;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >>a >> b;
        int u=0;
        for(int i=1;i<=b;i++)
        {
            int c;
            cin >> c;
            u = u|(1<<(c-1));
        }
        for(int i=0;i<(1<<12);i++)
        {
            if(dp[i]!=0x3f3f3f3f)
            {
                dp[i|u] = min(dp[i|u],dp[i]+a);
            }
        }
    }
    int sum=1;
    for(int i=1;i<n;i++)
    {
        sum = sum|(1<<i);
    }
    if(dp[sum]==0x3f3f3f3f)
    {
        cout << -1;
    }
    else
    {
        cout << dp[sum];
    }
    return 0;
}