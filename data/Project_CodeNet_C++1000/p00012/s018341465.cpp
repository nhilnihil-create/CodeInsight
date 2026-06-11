#include <iostream>
#include <complex>
#include <cmath>
using namespace std;

#define X real()
#define Y imag()
#define PI M_PI
#define EPS (1e-10)
typedef complex<double> point;

double angle(point a,point b,point c){ //?§????????¨????????????¢??°
	double A=abs(b-c);
	double B=abs(c-a);
	double C=abs(a-b);
	return acos((B*B+C*C-A*A)/(2.0*B*C)); //??????????????????
}

bool judge(point p,point a,point b,point c){
	double A=angle(p,a,b);
	double B=angle(p,b,c);
	double C=angle(p,c,a);
	return (abs(A+B+C-2*PI)<EPS)? true : false;
}

int main(void){
	point a,b,c,p;
	double x1,y1,x2,y2,x3,y3,xp,yp;

	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> xp >> yp){
		a.X=x1; a.Y=y1;
		b.X=x2; b.Y=y2;
		c.X=x3; c.Y=y3;
		p.X=xp; p.Y=yp;
		if(judge(p,a,b,c)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}