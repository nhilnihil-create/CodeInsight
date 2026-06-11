//g++  5.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N; cin>>N;
    vector<pair<ll,ll>> v;
    ll dp[N + 1][N + 1];
    memset(dp,0,sizeof(dp));
    
    for(ll i=0;i<N;++i)
    {
        ll val; cin>>val;
        v.push_back({val,i + 1});
    }
    
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    
    for(ll i=1;i<=N;++i)
    {
        ll x = 0; //elements from left
        ll y = i - x; //elements from right
        
        while(y >= 0)
        {
            if(x > 0)
                dp[x][y] = max(dp[x][y],dp[x - 1][y] + v[i - 1].first * abs(x - v[i - 1].second));
            
            if(y > 0)
                dp[x][y] = max(dp[x][y],dp[x][y - 1] + v[i - 1].first * abs(N - y + 1 - v[i - 1].second));
            
            y--;
            x++;
        }
    }
    
    ll ans = 0;
    for(ll i=0;i<=N;++i)
        ans = max(ans,dp[i][N - i]);
    
    cout<<ans<<endl;
}