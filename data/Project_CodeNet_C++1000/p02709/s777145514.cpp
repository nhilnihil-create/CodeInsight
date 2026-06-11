#include<bits/stdc++.h>
#define ll long long
#define dl double
using namespace std;

//***********************************************************************
int MAXNUM = 5e3+5;
vector <int>vis(MAXNUM);
vector<int> pr;
void sieve() {
	pr.push_back(2);
	for(ll i=3;i<MAXNUM;i+=2) if(!vis[i]) {
		pr.push_back(i);
		for(ll j=i*i;j<MAXNUM;j+=2*i) vis[j]=true;
	}
}
//************************************************************************
ll mod=1000000007;
void solve()
{
	ll n;
	cin >> n;
	vector<pair<ll,ll>> v(n+1);
	vector<vector<ll>> dp(n+1);
	dp[0].resize(n+1);
	for(int i=1;i<=n;i++)
	{
		dp[i].resize(n+1);
		ll x;
		cin >> x;
		v[i]=make_pair(x,i);
	}
	sort(++v.begin(),v.end());
	reverse(++v.begin(),v.end());
	dp[1][0]=v[1].first*(abs(n-v[1].second));
	dp[1][1]=v[1].first*(abs(1-v[1].second));
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			int bp=n-(i-1-j);
			dp[i][j]=max(dp[i][j],dp[i-1][j]+v[i].first*(abs(bp-v[i].second)));
			dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]+v[i].first*(abs(j+1-v[i].second)));
		}
	}
	ll ans=0;
	for(int i=0;i<=n;i++)
	{
		if(ans<dp[n][i])
		ans=dp[n][i];
	}
	cout << ans << endl;

}


int main()
{ 
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	ll t;
	//cin >> t;
	t=1;
	while(t--)
	{
		solve();
	}

	return 0;
}