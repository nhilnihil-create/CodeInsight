#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const ll N=410000,M=1001001;
struct node{
	ll x,id;
}f[N];
ll n,m,T,cnt,a[N],b[N],c[N],g[N],ans[N],x,y,z,k,aa,bb,cc;
bool mycmp(node a,node b)
{
	return a.x>b.x;
}
int main() 
{
	scanf("%lld%lld%lld%lld%lld",&x,&y,&aa,&bb,&cc);
	for (int i=1;i<=aa;i++) 
	{
		scanf("%lld",&a[i]);
		f[++m].x=a[i]; f[m].id=1;
	}
	for (int i=1;i<=bb;i++) 
	{
		scanf("%lld",&b[i]);
		f[++m].x=b[i]; f[m].id=2;
	}
	for (int i=1;i<=cc;i++) 
	{
		scanf("%lld",&c[i]);
		f[++m].x=c[i]; f[m].id=3;
	}
	sort(f+1,f+m+1,mycmp);
	ll ans=0;
	for (int i=1;i<=m;i++)
	{
		if (k>=x+y) break;
		if (f[i].id==1)
		{
			if (x) x-=1,ans+=f[i].x;
		}
		if (f[i].id==2)
		{
			if (y) y-=1,ans+=f[i].x;
		}
		if (f[i].id==3)
		{
			ans+=f[i].x;
			k++;
		}
	}
	printf("%lld",ans);
}