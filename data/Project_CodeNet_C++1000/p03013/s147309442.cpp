#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    long long n,m,i,k;
    cin>>n>>m;
    long long dp[n+1];
/*for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }*/
    memset(dp,-1,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    while(m--)
    {
        cin>>k;
        dp[k]=0;
    }
    for(i=2;i<=n;i++)
    {
        if(dp[i]!=0)
        {
           dp[i]=(dp[i-1]%1000000007+dp[i-2]%1000000007)%1000000007;
        }

    }
    /*for(auto i:dp)
    {
        cout<<i<< " ";
    }*/
    cout<<dp[n]<<endl;

    return 0;
}
