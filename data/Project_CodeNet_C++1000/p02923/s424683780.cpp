#include<iostream>
using namespace std;
int main()
{
    long long n,i,s=1,ma=0;;
    cin>>n;
    long long m[n];
    for(i=0;i<n;i++)
    {
        cin>>m[i];
    }
    long long dp[n];
    dp[0]=1;
    for(i=1;i<n;i++)
    {
        if(m[i]<=m[i-1])
        {
            dp[i]=dp[i-1]+1;
        }
        else
        {
            dp[i]=1;
        }
    }
    for(i=0;i<n;i++)
    {
        ma=max(ma,dp[i]);
    }
    cout<<ma-1<<endl;
    return 0;
}
