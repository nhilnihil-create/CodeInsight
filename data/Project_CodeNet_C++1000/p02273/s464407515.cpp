#include <cstdio>
#include <math.h>

using namespace std;

double co = cos(60.0*M_PI/180.0);
double si = sin(60.0*M_PI/180.0);

struct Point {double x, y;};


void koch(int n, struct Point p1, struct Point p2) {
	if (n==0) return;	//do nothing
	struct Point s,t,u;

	s.x = (2.0*p1.x+p2.x)/3.0;
	s.y = (2.0*p1.y+p2.y)/3.0;
	 
	t.x = (p1.x+2.0*p2.x)/3.0;
	t.y = (p1.y+2.0*p2.y)/3.0;

	u.x = (t.x-s.x)*co - (t.y-s.y)*si + s.x;
	u.y = (t.x-s.x)*si + (t.y-s.y)*co + s.y;

	koch(n-1,p1,s);
	printf("%.8f %.8f\n", s.x, s.y);
	
	koch(n-1,s,u);
	printf("%.8f %.8f\n", u.x, u.y);

	koch(n-1,u,t);
	printf("%.8f %.8f\n", t.x, t.y);

	koch(n-1,t,p2);
}

int main() {
	struct Point p1 = {0.0, 0.0};
	struct Point p2 = {100.0, 0.0};
	int n;
	scanf("%d\n",&n);
	printf("%f %f\n", p1.x,p1.y);

	koch(n, p1,p2);

	printf("%f %f\n", p2.x, p2.y);

	return 0;
}