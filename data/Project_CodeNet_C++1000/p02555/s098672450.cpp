#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define ll long long
ll dp[2010];

int main()
{
    int n;
    cin >> n;
    
    dp[0]=dp[1]=dp[2]=0;
    dp[3]=dp[4]=dp[5]=1;
    
    for(int i=6;i<=n;++i)
    {
        ll sum=0;
        for(int j=1;j<=i-3;++j)
        {
            sum+=dp[j]%mod;
        }
        (dp[i]+=sum+1)%=mod;
    }
    cout << dp[n] << "\n";
    
    return 0;
}
