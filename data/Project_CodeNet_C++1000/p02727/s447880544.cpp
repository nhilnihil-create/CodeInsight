#include <bits/stdc++.h>
#define N 110000
using namespace std;
int x,y,a,b,c,p1,p2,p3,i,minn;
int p[N],q[N],r[N];
long long ans;
bool cmp(int x,int y)
{
	return x>y;
} 
int main()
{
	scanf("%d%d%d%d%d",&x,&y,&a,&b,&c);
	for (i=1;i<=a;i++) scanf("%d",&p[i]);
	for (i=1;i<=b;i++) scanf("%d",&q[i]);
	for (i=1;i<=c;i++) scanf("%d",&r[i]);
	sort(p+1,p+a+1,cmp);
	sort(q+1,q+b+1,cmp);
	sort(r+1,r+c+1,cmp);
	for (i=1;i<=x;i++) ans+=p[i];
	for (i=1;i<=y;i++) ans+=q[i];
	p1=x;p2=y;p3=1;
	while ((p1>0||p2>0)&&p3<=c)
	{
		if (p1&&p2)
		{
		   minn=min(p[p1],q[p2]);
		   if (minn<r[p3]) 
		   {
		   ans+=r[p3]-minn;	
		   p3++;
	       } else break;
	       if (minn==p[p1]) p1--;else p2--;
		} else if (p1)
		{
			if (p[p1]<r[p3]) ans+=r[p3]-p[p1],p3++;else
			break;
			p1--;
		} else 
		{
			if (q[p2]<r[p3]) ans+=r[p3]-q[p2],p3++;else 
			break;
			p2--;
		 } 
	}
	printf("%lld",ans);
}
