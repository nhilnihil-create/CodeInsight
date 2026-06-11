#include<iostream>
#include <iomanip>
#include <math.h>
using namespace std;
struct Point  {
	double x;
	double y;
	Point(double _x,double _y):x(_x),y(_y){}
	Point operator+(const Point & a) const {
		return	Point(x + a.x,y + a.y);
	}
	Point operator-(const Point & a) const {
		return	Point(x - a.x,y - a.y);
	}
	Point operator*(const int r) const {
		return	Point(x * r,y * r);
	}
	Point operator/(const int r) const {
		return	Point(x / r,y / r);
	}
	void print()const{
		cout << fixed << std::setprecision( 6 )  << x << " " << y << std::endl;
	}
};
Point computeTriangleTop(const Point s,const Point t){
	Point a = t - s;
	const double pi = 3.14159265359879;
	const double cos60 = cos(pi / 3);
	const double sin60 = sin(pi / 3);
	return	s + 
		Point(cos60*a.x - sin60*a.y,
				sin60*a.x + cos60*a.y);
}
void KochCurve(int level, int n, Point p1,Point  p2) {
	if (level == n){
		p2.print();
		return;
	}
	Point s = (p1*2 + p2) / 3;
	Point t = (p1 + p2*2) / 3;
	Point u = computeTriangleTop(s,t);
	KochCurve(level+1,n,p1,s);
	KochCurve(level+1,n,s,u);
	KochCurve(level+1,n,u,t);
	KochCurve(level+1,n,t,p2);
}

int main(){
	int n;
	cin >> n;
	Point P1(0,0),P2(100,0);
	P1.print();
	::KochCurve(0,n,P1,P2);
}