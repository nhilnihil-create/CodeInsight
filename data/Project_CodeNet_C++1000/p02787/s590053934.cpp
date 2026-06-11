#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long h,n;
    cin>>h>>n;

    vector<long long> value(n),cost(n);
    long long mi = INT_MAX;
    long long micost = INT_MAX;
    for(int i = 0;i<n;i++)
    {
        cin>>value[i]>>cost[i];
        mi = min(mi,value[i]);
        micost = min(micost,cost[i]);
    }

    vector<long long> dp(h+1,INT_MAX);
    for(int i = 1;i<=min(h,mi);i++)
    {
        dp[i] = micost;
    }

    for(int i = mi + 1;i<=h;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(value[j] >= i)
            {
                dp[i] = min(dp[i],cost[j]);
            }
            else
            {
                dp[i] = min(dp[i],(cost[j] + dp[i-value[j]]));
            }
        }
    }

    cout<<dp[h];

    return 0;
}