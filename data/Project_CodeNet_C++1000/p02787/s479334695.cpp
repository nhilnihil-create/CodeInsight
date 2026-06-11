#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int inf=1e18;
int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("in","r", stdin);
		freopen("out","w",stdout);
	#endif

	int h,n;
	cin>>h>>n;
	vector<int> dp(h+1, inf);
	dp[h]=0;int a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;

		for(int j=h;j>=0;j--)
		{
			int x=min(a,j);
			dp[j-x]=min(dp[j]+b,dp[j-x]);
		}
	}
	
	cout<<dp[0];


}