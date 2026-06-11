#include<cstdio>
#include<functional>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int main(void)
{
	int a,b,h,m;
	double r,c,c2;
	scanf("%d %d %d %d",&a,&b,&h,&m);
	r=(double)m*M_PI/30.0-((double)h+(double)m/60.0)*M_PI/6.0;
	c=(double)a*a+(double)b*b-2.0*(double)a*b*cos(r);
	c2=sqrt(c);
	printf("%.9lf\n",c2);
	return 0;
}