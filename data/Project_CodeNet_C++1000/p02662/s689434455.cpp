//tricky question refer h_p_s and revise
// also see editorial
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=998244353;
ll dp[3001][3001];
int main ()
{
    ll n,sum;
    cin>>n>>sum;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
    cin>>v[i];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<=sum;j++)
        {
            dp[i][j]=(2*dp[i-1][j])%M;
            if(j-v[i-1]>=0)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j-v[i-1]])%M;
            }
        }
    }
    cout<<dp[n][sum];
    return 0;
}