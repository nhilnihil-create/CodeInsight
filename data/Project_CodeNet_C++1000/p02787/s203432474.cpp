#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	const int INF=1e8;
	int H,N;
	cin>>H>>N;
	int max_size=H+1e4+1;
	vector<int> dp(max_size,INF);
	dp[0]=0;
	rep(i,N)
	{
		int a,b;
		cin>>a>>b;
		rep(k,max_size-a)
		{
			dp[k+a]=min(dp[k+a],dp[k]+b);
		}
	}
	int ans=INF;
	Rep(i,H,max_size)
	{
		ans=min(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
