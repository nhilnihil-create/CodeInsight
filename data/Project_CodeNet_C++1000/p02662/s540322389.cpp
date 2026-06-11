#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
const int N=1e6+5;
const long long INF = 1e6;
const int mod=998244353;
int n,s,dp[3005][3005];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>s;
    dp[0][0]=1;
    vector<int> v(n+5,0);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            dp[i][j]+=(2*dp[i-1][j])%mod;
            if(j>=v[i])
            {
                dp[i][j]+=dp[i-1][j-v[i]];
                dp[i][j]=dp[i][j]%mod;
            }
        }
    }
    cout<<dp[n][s];



}
