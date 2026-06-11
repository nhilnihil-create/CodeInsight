#include<bits/stdc++.h>
const int mod=1e9+7;
typedef long long ll;
using namespace std;

ll dp[2005];
int main()
{
    for(int i=0;i<=2004;i++) dp[i]=1;
    dp[0]=0;
    dp[1]=0;
    dp[2]=0;
    dp[3]=1;
    int n;cin>>n;
    for(int i=4;i<=n;i++)
    {
        for(int j=3;j<=i-3;j++)
            dp[i]=(dp[i]+dp[j])%mod;
    }
    cout<<dp[n];
    return 0;
}
