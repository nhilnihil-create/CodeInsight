#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll

int32_t main()
{
	#ifdef ONLINE_JUDGE
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#endif
	
	int n,x,y;
	cin>>n>>x>>y;
	int dist[n+1][n+1];
	dist[x][y]=1;
	for(int i=1;i<=n;i++)
	{
		//if(i==x or i==y)continue;
		dist[i][x]=dist[x][i]=abs(x-i);
		dist[i][y]=dist[y][i]=abs(y-i);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			dist[i][j]=dist[j][i]=min(abs(i-j),dist[i][x]+dist[y][j]+1);
		}
	}
	vector<int> f(n);
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	{f[dist[i][j]]++;}
	for(int i=1;i<n;i++)cout<<f[i]<<'\n';
	
}