#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define rep2(x,from,to) for(int x=(from);x<(to);++(x))
#define rep(x,to) rep2(x,0,to)
int n;
double pi = acos(-1);
void koch(double xl, double yl, double xr, double yr, int depth) {
	if(depth == n) {
		printf("%.8lf %.8lf\n", xr, yr);
		return;
	}
	double px =(xr-xl)/3+xl, py = (yr-yl)/3+yl;
	double qx =(xr-xl)*2/3+xl, qy = (yr-yl)*2/3+yl;
	double len = sqrt(pow(xr-xl,2.0) + pow(yr-yl,2.0))/3.0;
	double rad = atan2(yr-yl,xr-xl);
	koch(xl,yl,px,py,depth+1);
	koch(px,py,len*cos((pi/3)+rad)+px,len*sin((pi/3)+rad)+py,depth+1);
	koch(len*cos((pi/3)+rad)+px,len*sin((pi/3)+rad)+py,qx,qy,depth+1);
	koch(qx,qy,xr,yr,depth+1);
}
int main() {
	cin >> n;
	printf("%.8lf %.8lf\n",0,0);
	koch(0,0,100,0,0);
	return 0;
}