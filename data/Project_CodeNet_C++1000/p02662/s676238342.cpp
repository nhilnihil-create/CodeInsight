#include <bits/stdc++.h>
#include <stdio.h>
#define ll long long
#define fr(i,p,n) for(ll i=p;i<n;i++)
#define fr1(i,p,n) for(ll i=p;i>=n;i--)
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define precise cout << std::setprecision(15) << std::fixed;
using namespace std;

ll dp[3005][3005];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        ll n,s;
        cin>>n>>s;
        ll a[n+1];
        fr(i,1,n+1) cin>>a[i];
        dp[0][0]=1;
        fr(i,1,n+1)
        {
            fr(j,0,s+1)
            {
                if(j-a[i]>=0)
                    dp[i][j]+=(dp[i-1][j-a[i]])%MOD1;
                dp[i][j]%=MOD1;
                dp[i][j]+=(dp[i-1][j]*2)%MOD1;
                dp[i][j]%=MOD1;
            }
        }
        cout<<dp[n][s]<<endl;
    }
    return 0;
}
