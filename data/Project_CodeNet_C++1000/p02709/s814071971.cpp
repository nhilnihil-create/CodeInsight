#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[2001][2001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif
	    ll n;
	    cin>>n;
	    ll a[n+1];
	    vector<pair<ll,ll>>v;
	    for(ll i=1;i<=n;i++)
	    {	
	    	cin>>a[i];
	    	v.push_back(make_pair(a[i],i));
	    }
	    sort(v.begin(),v.end());
	    reverse(v.begin(),v.end());
	    for(ll i=1;i<=n;i++)
	    {
	    	//cout<<v[i-1].first<<" "<<v[i-1].second<<endl;
	    	dp[i][0]=dp[i-1][0]+(v[i-1].first)*(abs(v[i-1].second-i));
	    	dp[0][i]=dp[0][i-1]+(v[i-1].first)*(abs(v[i-1].second-(n-i+1)));
	    	for(ll j=1;j<i;j++)
	    	{
	    		dp[i-j][j]=max(dp[i-j-1][j]+v[i-1].first*abs(v[i-1].second-(i-j)),dp[i-j][j-1]+v[i-1].first*abs(v[i-1].second-(n-j+1)));
	    	}
	    }
	    //cout<<dp[1][0]<<endl;
	    //cout<<dp[1][1]<<endl;
	    ll maxi=0;
	    //cout<<dp[n][0]<<endl;
	    //cout<<dp[0][n]<<endl;
	    for(ll j=0;j<=n;j++)
	    {
	    	//cout<<dp[n-j][j]<<endl;
	    	maxi=max(maxi,dp[n-j][j]);
	    }
	    cout<<maxi;
}