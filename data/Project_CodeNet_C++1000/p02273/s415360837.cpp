#include <cstdio>
#include <cmath>
using namespace std;

struct P{
	double x,y;
};
const double th=M_PI*60.0/180.0;

void koch(int n,P a,P b){
	if(n==0)
		return ;
	P s,t,u;
	s.x=(2*a.x+b.x)/3;
	s.y=(2*a.y+b.y)/3;
	t.x=(a.x+2*b.x)/3;
	t.y=(a.y+2*b.y)/3;
	u.x=(t.x-s.x)*cos(th)-(t.y-s.y)*sin(th)+s.x;
	u.y=(t.y-s.y)*cos(th)+(t.x-s.x)*sin(th)+s.y;
	koch(n-1,a,s);
	printf("%.5f %.5f\n",s.x,s.y);
	koch(n-1,s,u);
	printf("%.5f %.5f\n",u.x,u.y);
	koch(n-1,u,t);
	printf("%.5f %.5f\n",t.x,t.y);
	koch(n-1,t,b);
}

int main(){
	int n;
	scanf("%d",&n);
	P a={0,0},b={100.0,0};
	printf("%.5f %.5f\n",a.x,a.y);
	koch(n,a,b);
	printf("%.5f %.5f\n",b.x,b.y);
	return 0;
}