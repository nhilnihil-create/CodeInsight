#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009
int main(void){
	double x, y, rad;
	double s, l, h;
	scanf("%lf %lf %lf", &x, &y, &rad);
	rad = rad*3.1415926536 / 180;
	s = x*y*(sin(rad)) / 2;
	l = (x*x) + (y*y) - (2 * x*y*cos(rad));
	l = sqrt(l);
	l += x + y;
	h = 2 * s / x;
	printf("%f\n%f\n%f\n", s, l, h);
	return 0;
}