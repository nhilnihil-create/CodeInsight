#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=2010;
int n;
struct da{int v,id;}q[maxn];
long long dp[maxn][maxn];
inline bool cmp(da aa,da bb){return aa.v>bb.v;}
long long dfs(int l,int r)
{
	if (dp[l][r]!=-1) return dp[l][r];
	if (l>r) return 0;
	da now=q[l+n-r];
	dp[l][r]=max(dp[l][r],dfs(l,r-1)+1ll*now.v*abs(r-now.id));
	dp[l][r]=max(dp[l][r],dfs(l+1,r)+1ll*now.v*abs(l-now.id));
return dp[l][r];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&q[i].v),q[i].id=i;
	sort(q+1,q+n+1,cmp);
	memset(dp,-1,sizeof dp);
	printf("%lld\n",dfs(1,n));
return 0;
}