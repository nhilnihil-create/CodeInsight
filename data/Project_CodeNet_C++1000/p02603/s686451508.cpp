#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<int,int>
#define endl "\n"
#define MAXN 100005
#define mod 1000000007
using namespace std;

void solve()
{
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    solve();
    ll n;
    cin>>n;
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        /* code */
        cin>>a[i];
    }
    vector<ll> dp(n, 0);
    dp[0] = 1000;
    for(ll i=1; i<n; i++)
    {
        dp[i] = dp[i-1];
        for(ll j=0; j<i; j++)
        {
            ll stocks_bought = dp[j]/a[j];
            ll profit = stocks_bought*a[i] - stocks_bought*a[j];
            dp[i] = max(dp[i], dp[j] + profit);
        }
    } 
    cout<<dp[n-1]<<'\n';
}