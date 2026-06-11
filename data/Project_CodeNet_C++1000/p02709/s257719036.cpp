#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int N=2003;
int dp[N][N];
int ans;
void cmax(int &x,int y){x=max(x,y);}
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int n;
	cin>>n;
	pair<int,int> a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i].first,a[i].second=i;
	sort(a+1,a+n+1);reverse(a+1,a+n+1);


	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			int l=j;
			int r=i-1-j;
			cmax(dp[l+1][r],dp[l][r]+abs(l+1-a[i].second)*a[i].first);
          	r=j;l=i-1-j;
			cmax(dp[l][r+1],dp[l][r]+abs(n-r-a[i].second)*a[i].first);

		}
	}
	for(int i=0;i<=n;i++)cmax(ans,dp[i][n-i]);
	cout<<ans<<"\n";
}

