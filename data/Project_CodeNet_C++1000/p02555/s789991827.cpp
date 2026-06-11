#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define mod 1000000007


signed main()
{
    int i,j,n;
    cin>>n;
    if(n==0) cout<<1<<endl;
    else if(n<3) cout<<0<<endl;
    else
    {
        int dp[n+1]={0};
    dp[3]=1;
    dp[0]=1;
    for(i=4;i<=n;i++)
    {
        for(j=i-3;j>=0;j--)
        {
            dp[i]+=dp[j];
            dp[i]%=mod;
        }
    }
    cout<<dp[n];
    }
}
