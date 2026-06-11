#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const long long maxn=2500+10;
long long n,dp[maxn][maxn];
struct node
{
	long long w,id;
}a[maxn];
long long cmp(node x,node y)
{
	return x.w>y.w;
}
int main()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i].w),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	for(long long i=1;i<=n;i++)
	{
		for(long long j=0;j<=i-1;j++)
		{
			long long k=i-1-j;
			dp[j+1][k]=max(dp[j+1][k],dp[j][k]+a[i].w*abs(a[i].id-(j+1)));
			dp[j][k+1]=max(dp[j][k+1],dp[j][k]+a[i].w*abs(a[i].id-(n-k)));
		}
	}
	long long maxx=0;
	for(long long i=0;i<=n;i++)maxx=max(maxx,dp[i][n-i]);
	printf("%lld\n",maxx);
	return 0;
}