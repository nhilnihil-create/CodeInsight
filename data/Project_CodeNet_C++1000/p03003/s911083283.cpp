#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long 
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back 
#define mp make_pair
#define inf 2000000009
#define mod 1000000007
using namespace std;

int main()
{ 
    fast;

    ll n,m,x;
    cin>>n>>m;

    vector<ll> s(n),t(m);
    for(ll i=0;i<n;i++)
      cin>>s[i];
    for(ll i=0;i<m;i++)
      cin>>t[i];

    ll dp[n+1][m+1];
    memset(dp,0,sizeof(dp));

    for(ll i=0;i<=n;i++)
      dp[i][0]=1;
    for(ll i=0;i<=m;i++)
      dp[0][i]=1;

    for(ll i=1;i<=n;i++)
    {
      for(ll j=1;j<=m;j++)
      {
        dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mod)%mod;

        if(s[i-1]==t[j-1])
         dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
      }
    }
    cout<<dp[n][m]<<endl;
 }
