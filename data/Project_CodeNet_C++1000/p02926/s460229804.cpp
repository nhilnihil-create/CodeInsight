#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000;
struct node
{
	int x,y;
	double d;
}e[maxn];
bool cmp(node a,node b)
{
	return a.d<b.d;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>e[i].x>>e[i].y;
		e[i].d=atan2(e[i].y*1.0,e[i].x*1.0);
	}
	int nxt[1000];
	for(int i=0;i<n-1;i++)
		nxt[i]=i+1;
	nxt[n-1]=0;
//	for(int i=0;i<n;i++)
//		cout<<nxt[i]<<' ';
	sort(e,e+n,cmp);
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		ll dx=e[i].x,dy=e[i].y;
		ans=max(ans,(ll)dx*dx+dy*dy);
		for(int j=nxt[i];j!=i;j=nxt[j])
		{
			dx=dx+e[j].x;dy=dy+e[j].y;
			ans=max(ans,(ll)dx*dx+dy*dy);
		}
	}
	printf("%.15lf",sqrt(ans)); 
	return 0;
 } 