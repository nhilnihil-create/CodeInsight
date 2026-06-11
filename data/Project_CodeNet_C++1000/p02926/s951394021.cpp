#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct node{
	int x;int y;
}aa[456];

bool cmp(node a,node b)
{
	return atan2(a.x,a.y)<atan2(b.x,b.y);
}
int main()
{
	long long n,x,y;
	long long ans=0;
	cin>>n;
	for(int i=0;i<n;i++)	cin>>aa[i].x>>aa[i].y;
	sort(aa,aa+n,cmp);
	for(int i=0;i<n;i++)
	{
		x=aa[i].x;y=aa[i].y;
		ans=max(ans,x*x+y*y);
		for(int j=(i+1)%n;j!=i;j=(j+1)%n)
		{
			x+=aa[j].x;y+=aa[j].y;
			ans=max(ans,x*x+y*y);
		}
	}
	double res=sqrt(ans);
	printf("%.13lf\n",res);
	return 0;
}