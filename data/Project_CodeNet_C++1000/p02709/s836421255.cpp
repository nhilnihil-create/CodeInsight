#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

#define ll long long 
#define read(x) scanf("%d",&x)

struct node
{
	int id,val;
}a[2005];
ll dp[2005][2005];
int n;

bool cmp(node n,node m){return n.val<m.val;}

int main()
{
	read(n);
	for(int i=1;i<=n;i++) read(a[i].val),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) dp[i][i]=1ll*a[1].val*abs(a[1].id-i);
	for(int i=2;i<=n;i++)
	{
		for(int l=1;l+i-1<=n;l++)
		{
			int r=l+i-1;
			dp[l][r]=0;
			dp[l][r]=max(dp[l][r],max(dp[l+1][r]+1ll*a[i].val*abs(a[i].id-l),dp[l][r-1]+1ll*a[i].val*abs(a[i].id-r)));
		}
	}
	printf("%lld\n",dp[1][n]);
}
