#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,v,p;
int m,a[100005];
bool cmp(int a,int b)
{
	return a>b;
}
int l,r,mid;
int ans;
bool check(int x)
{
	if(x<=p) return true;
	if(a[x]+m<a[p]) return false;
	int now=m*(p-1+n-x+1);
	for(int i=p+1;i<x;i++){
		now+=a[x]+m-a[i];
	}now+=a[x]+m-a[p];
	return now>=m*v;
}
signed main()
{
	cin>>n>>m>>v>>p;
	for(int i=1;i<=n;++i)
	cin>>a[i];
	sort(a+1,a+1+n,cmp);
	l=1,r=n;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		r=mid-1;
	}
	printf("%lld\n",ans);
	return 0;
}