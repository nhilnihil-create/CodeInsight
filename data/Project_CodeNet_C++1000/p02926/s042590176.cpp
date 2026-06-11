#include<bits/stdc++.h>
#include<cmath>
using namespace std;
typedef long long ll; 
const int N = 110;
struct node{
	ll x,y;
}r[N];
//ll nx[N];

bool cmp(node a,node b)
{
	return atan2(a.y,a.x)<atan2(b.y,b.x);
}
int main()
{
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>r[i].x>>r[i].y;
	sort(r+1,r+n+1,cmp);
	ll nx[N];//用于循环 
	for(ll i=1;i<=n;i++) nx[i]=i+1;
	nx[n]=1;
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		ll X=r[i].x,Y=r[i].y;
		ans=max(ans,X*X+Y*Y);
		for(ll j=nx[i];j!=i;j=nx[j])
		{
			X+=r[j].x;
			Y+=r[j].y;
			ans=max(ans,X*X+Y*Y);
		}
	}
	printf("%.10lf\n",sqrt(ans));
	return 0;
}