#include <bits/stdc++.h>
using namespace std;
const double eps=1e-12,pi=acos(-1);
int n,ans;
double ang,x,y,dx,dy=1;
int main()
{
	scanf("%d",&n);
	ang=n/180.0*pi;
	while (true)
	{
		x+=dx;
		y+=dy;
		ans++;
		if (fabs(x)<eps && fabs(y)<eps) break;
		double tmp=dx*sin(ang)+dy*cos(ang);
		dx=dx*cos(ang)-dy*sin(ang);
		dy=tmp;
	}
	printf("%d\n",ans);
	return 0;
}
