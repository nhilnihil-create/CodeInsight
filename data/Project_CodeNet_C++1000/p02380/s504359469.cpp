#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	double a,b,c;
	cin >> a >> b >> c;
	double d = c*M_PI/180;
	double h = b*sin(d);
	double m = sqrt(a*a+b*b-2*a*b*cos(d));
	double s = a*h/2;
	cout << fixed << setprecision(10);
	cout << s << endl;
	cout << a+b+m << endl;
	cout << s/a*2 << endl;
}