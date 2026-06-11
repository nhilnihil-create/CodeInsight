#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=110000;
const int inf=10000000000000000;
int n,m,v,p;
int a[maxn];
int check(int pos)
{
	int cost=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=a[pos]||a[i]>a[pos]+m)
		{
			cost+=m;
			if(a[i]>a[pos]+m) cnt++;
		}
		else cost+=a[pos]+m-a[i];
		
	}
	if(cost>=m*v) return cnt;
	for(int i=n;i>=1;i--)
	{
		if(a[i]<=a[pos]||a[i]>a[pos]+m) continue;
		cost+=a[i]-a[pos];
		cnt++;
		if(cost>=m*v) break;
	}
	return cnt;
}
signed main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&v,&p);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=n,best=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)+1<=p) best=mid,r=mid-1;
		else l=mid+1;
	}
	if(best==-1) printf("0\n");
	else printf("%lld\n",n-best+1);
	return 0;
}