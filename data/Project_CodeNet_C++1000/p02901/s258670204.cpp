#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int inf=1e18;

int32_t main()
{
	#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#endif
	int n,m,x;
	cin>>n>>m;
	vector<int> dp(4100, inf);
	vector<int> a(m),b(m),c(m);
	for(int i=0;i<m;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=0;j<b[i];j++)
		{
			cin>>x;x--;
			c[i]|=(1<<x);
		}
	}
	dp[0]=0;
	for(int i=0;i<m;i++)
	{
		for(int mask=0;mask<(1<<n);mask++)
		{
			dp[mask|c[i]]=min(dp[mask|c[i]], dp[mask]+a[i]);
		}
	}
	if(dp[(1<<n)-1]==inf)cout<<-1;
	else cout<<dp[(1<<n)-1];
	
}