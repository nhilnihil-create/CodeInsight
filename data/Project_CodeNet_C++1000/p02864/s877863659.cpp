#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long LL;
const int M=305;
const LL INF=(LL)M*(1000000000);

LL dp[2][M]; // dp[i][j] i block end at j
// if k=0 ans=\sum_{1~n} {h[i]-h[i-1]} (h[0]=0)
// if k>0 should change k blocks as the left one of themselves

LL h[M];

int n,k;
struct BIT
{
	LL mi[M];
	void init(int n)
	{
		for(int i=1;i<=n;i++)
			mi[i]=INF;
	}
	int lowbit(int x)
	{
		return x&(-x);
	}
	void add(int p,LL v)
	{
		for(;p<=n;p+=lowbit(p))
			mi[p]=min(v,mi[p]);
	}
	LL query(int p)
	{
		LL ans=INF;
		for(;p;p-=lowbit(p))
			ans=min(ans,mi[p]);
		return ans;
	}
}bit1,bit2;
// maintain dp[i][k] and dp[i][k]-h[k]

LL d[M];
int m;
int id(int x)
{
	return lower_bound(d,d+m,x)-d+1;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&h[i]);
		d[i]=h[i];
	}
	sort(d,d+1+n);
	m=unique(d,d+1+n)-d;
	for(int i=1;i<=n;i++)
		dp[0][i]=INF;
	for(int i=1;i<=n-k;i++)
	{
		bit1.init(m);
		bit2.init(m);
		for(int j=0;j<=n;j++)
			dp[i&1][j]=INF;
		for(int j=i;j<=n;j++)
		{
			bit1.add(id(h[j-1]),dp[(i+1)&1][j-1]-h[j-1]);
			bit2.add(m+1-id(h[j-1]),dp[(i+1)&1][j-1]);
			dp[i&1][j]=min(bit1.query(id(h[j]))+h[j],bit2.query(m+1-id(h[j])));
			//cout<<i<<" "<<j<<" "<<dp[i&1][j]<<endl;
		}
	}
	LL ans=INF;
	for(int i=n-k;i<=n;i++)
		ans=min(ans,dp[(n-k)&1][i]);
	printf("%lld\n",ans);
	return 0;
}