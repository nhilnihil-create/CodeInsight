#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n ,m;
    cin>>n>>m;
    set<ll> s;
    for(int i=0;i<m;i++)
    {
        ll temp;
        cin>>temp;
        s.insert( temp);
    }
    ll * dp = new ll [n+1]();
    dp[0] =1;
    for(int i=1;i<=n;i++)
    {
        if( s.count(i) )
            continue;
        dp[i] = (dp[i] + dp[i-1] ) % 1000000007;
        if( i-2 >=0 )
        {
            dp[i] = (dp[i] + dp[i-2] ) % 1000000007;
        }
    }
    cout<<dp[n];
}