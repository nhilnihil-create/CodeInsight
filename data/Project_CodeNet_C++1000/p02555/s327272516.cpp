#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<int>> vvi;

ll rec(ll SS, vi& dp)
{
    ll ans = 0;

    if(SS == 0)
    return 1;
    if(SS < 0)
    return 0;

    if(dp[SS] != -1)
    return dp[SS];

    for(ll i = 3 ; i <= SS ; i++)
    ans += rec(SS-i,dp) % 1000000007 ;

    return dp[SS] = ans;
}

int main()
{
    ll S;    
    cin >> S;
    vi dp(S+1,-1);
    cout << rec(S,dp) % ( 1000000007 );

    // for(auto x : dp)
    // cout << x << " ";
}