#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    int h,n; cin>>h>>n;
    long long a[n]={}, b[n]={};
    long long dp[n][h+1]={};
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];

    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=h;j++)
        {
            if(i==0)
            {
                if(j%a[i]==0) dp[i][j] = b[i]*(j/a[i]);
                else dp[i][j] = b[i]*(j/a[i]+1);
                continue;
            }

            if(j<a[i]) dp[i][j] = min(dp[i-1][j],b[i]);
            else dp[i][j] = min(dp[i-1][j],dp[i][j-a[i]]+b[i]);
        }
    }

    cout<<dp[n-1][h];
}