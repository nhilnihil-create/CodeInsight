#include<iostream>
#include<math.h>
using namespace std;

struct Point{
	double x;
	double y;
};

int Kcurve(int n, Point p1, Point p2){
	if (n==0){
		return 0;
	}
	Point a,b,c;
	a.x=(2.0/3.0)*p1.x+(1.0/3.0)*p2.x;
	a.y=(2.0/3.0)*p1.y+(1.0/3.0)*p2.y;
	b.x=p1.x+(1.0/2.0)*(p2.x-p1.x)-(1.0/(2*sqrt(3)))*(p2.y-p1.y);
	b.y=p1.y+(1.0/(2*sqrt(3)))*(p2.x-p1.x)+(1.0/2.0)*(p2.y-p1.y);
	c.x=(1.0/3.0)*p1.x+(2.0/3.0)*p2.x;
	c.y=(1.0/3.0)*p1.y+(2.0/3.0)*p2.y;
	
	Kcurve(n-1,p1,a);
	cout << a.x << " " << a.y << endl;
	Kcurve(n-1,a,b);
	cout << b.x << " " << b.y << endl;
	Kcurve(n-1,b,c);
	cout << c.x << " " << c.y << endl;
	Kcurve(n-1,c,p2);
	
	return 0;
}
int main(){
	Point a,b;
	a.x=0.0;
	a.y=0.0;
	b.x=100.0;
	b.y=0.0;
	int n;
	cin >> n;
	cout << 0 << " " << 0 << endl;
	Kcurve(n,a,b);
	cout << 100 << " " << 0 << endl;
	return 0;
}