#include <stdio.h>
#include <math.h>
int n,A[50];
struct P{
	double x;
	double y;
}; 
void print(struct P p){
	printf("%.8f %.8f\n",p.x,p.y);
}
void koch(int n,struct P p1,struct P p2){
	if(n==0)
		return;
	double th = M_PI * 60.0 / 180.0;
	struct P s,u,t;
	s.x=(2.0*p1.x+1.0*p2.x)/3.0;
	s.y=(2.0*p1.y+1.0*p2.y)/3.0;
	t.x=(1.0*p1.x+2.0*p2.x)/3.0;
	t.y=(1.0*p1.y+2.0*p2.y)/3.0;	
	u.x=(t.x-s.x)*cos(th)-(t.y-s.y)*sin(th)+s.x;
	u.y=(t.x-s.x)*sin(th)+(t.y-s.y)*cos(th)+s.y;
	
	koch(n-1,p1,s);
	print(s);
	koch(n-1,s,u);
	print(u);
	koch(n-1,u,t);
	print(t);
	koch(n-1,t,p2);
}

int main() {
	struct P a,b;
	int n;
	
	scanf("%d",&n);
	
	a.x=0;a.y=0;
	b.x=100;b.y=0;
	
	print(a);
	koch(n,a,b);
	print(b);
	
	return 0;
}