#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main()
{
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr;
    for(int i=0;i<n;i++)
    {
        ll x;cin>> x;
        arr.push_back({x,i});
        
    }
    sort(arr.begin(),arr.end(),greater<pair<ll,ll>>());
    
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,INT_MIN));
    
    dp[0][0]=0;
    for( ll i=0;i<n;i++)
    {
        ll curr  = arr[i].first;
        ll idx  = arr[i].second;
        
        for(ll j=0;j<=i;j++)
        {
            if(dp[i][j]!=INT_MIN)
        {        dp[i+1][j+1] = max(dp[i+1][j+1],curr*abs(idx-j) + dp[i][j]);
                dp[i+1][j] =  max(dp[i+1][j], abs (n-1-(i-j)-idx)*curr+ dp[i][j]);
        
        }
        }
        
    }
ll ans =-1;
for(int i=0;i<=n;i++)
ans= max(ans,dp[n][i]);

cout<< ans<<endl;
}