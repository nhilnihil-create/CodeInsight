#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long dp[100005][2];
int main()
{
    char s[100005];
    cin>>s+1;
    dp[0][1]=1;
    dp[0][0]=0;
    int n=strlen(s+1);
    for(int i=1;s[i];i++)
    {
        dp[i][0]=(dp[i-1][0]*3)%mod;
        if(s[i]=='1')
        {
            dp[i][1]=(dp[i-1][1]*2)%mod;
            dp[i][0]+=dp[i-1][1];
            dp[i][0]=(dp[i][0])%mod;
        }
        else
        {
            dp[i][1]=dp[i-1][1];
        }
    }
    printf("%lld\n",(dp[n][1]+dp[n][0])%mod);
}