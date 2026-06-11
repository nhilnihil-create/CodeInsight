#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+10;
int n,m,v,p;
int a[maxn];
bool check(int x)
{
	if(x<p)
		return true;
	int sum=0;
	int need=x-p+1;
	for(int i=x-1;i>=0;i--)
	{
		if(need==0)
			break;
		int c=a[i]-a[x];
		if(c>m)
			return false;
		sum+=c;
		--need;
	}
	return sum<=(n-v)*m;
}
signed main()
{
	scanf("%d%d%d%d",&n,&m,&v,&p);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	sort(a,a+n);
	reverse(a,a+n);
	int l=0,r=n-1;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	printf("%d\n",l+1);
	return 0;
}