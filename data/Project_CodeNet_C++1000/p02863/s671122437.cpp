#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MN = 6005;
#define pb push_back
#define pii pair<int,int>

int t;
int n,m;
pii A[MN];
int f[MN][MN],g[MN][MN];
int dp[MN];
int main()
{
	memset(f,0,sizeof f);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d%d",&A[i].first,&A[i].second);
	sort(A+1,A+1+n);
//	for(int i=1;i<=n;++i) printf("(%d,%d,%d)\n",i,A[i].first,A[i].second);
	for(int i=1;i<=n;++i)
	{
		int c = A[i].first, w = A[i].second;
		for(int j=0;j<m;++j) f[i][j] = f[i-1][j];
		for(int j=m-1;j>=c;--j)
		{
//			dp[j] = max(dp[j],dp[j-c]+w);
			f[i][j] = max(f[i-1][j],f[i-1][j-c]+w);
		}
	}
	for(int i=n;i>=1;--i)
	{
		int c = A[i].first, w = A[i].second;
		for(int j=0;j<m;++j) g[i][j] = g[i+1][j];
		for(int j=m-1;j>=c;--j)
		{
//			dp[j] = max(dp[j],dp[j-c]+w);
			g[i][j] = max(g[i-1][j],g[i-1][j-c]+w);
		}
	}
	int ans = 0;
	for(int i=1;i<=n;++i)
	{
		int w = A[i].second;
		for(int j=0;j<m;++j)
		{
			
			ans = max(ans,f[i-1][j]+w+g[i+1][m-j-1]);
		}
	}
	printf("%d\n",ans);
}