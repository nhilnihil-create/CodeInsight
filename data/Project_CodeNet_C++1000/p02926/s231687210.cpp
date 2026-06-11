#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int N=100010;
struct node
{
	int x,y;
}bb[N];
bool cmp(node a,node b)
{
	return atan2(a.y,a.x)<atan2(b.y,b.x);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&bb[i].x,&bb[i].y);
	}
	sort(bb,bb+n,cmp);
	ll maxx=0;
	for(int i=0;i<n;i++)
	{
		ll x=bb[i].x,y=bb[i].y;
		maxx=max(maxx,x*x+y*y);
		for(int j=(i+1)%n;j!=i;j=(j+1)%n)
		{
			x+=bb[j].x,y+=bb[j].y;
			maxx=max(maxx,x*x+y*y);
		}
	} 
	printf("%.10lf",sqrt(maxx));
}