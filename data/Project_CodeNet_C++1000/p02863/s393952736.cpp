#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 3005;
int t;
int n,m;
int c[MN],w[MN]; 
int f[MN][MN],g[MN][MN];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>c[i]>>w[i];
	
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=m;++j) f[i][j] = f[i-1][j];
		for(int j=m;j>=c[i];--j) 
		{
			f[i][j] = max(f[i-1][j],f[i-1][j-c[i]]+w[i]);
		}
	}
	for(int i=n;i>=1;--i)
	{
		for(int j=0;j<=m;++j) g[i][j] = g[i+1][j];
		for(int j=m;j>=c[i];--j) 
		{
			g[i][j] = max(g[i+1][j],g[i+1][j-c[i]]+w[i]);
		}
	}
	int ans = 0;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<m;++j)
		{
			 ans = max(ans,f[i-1][j]+w[i]+g[i+1][m-j-1]);
		}
	}
	cout<<ans<<"\n";
}