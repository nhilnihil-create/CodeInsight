#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
	long double a,b,c,s,l,h;
	cin >> a >> b >> c;
	h = b*sinl(c*3.1415926535/180);
	s = a*h*0.5;
	l = a + b + sqrtl(a*a + b*b - 2*a*b*cosl(c*3.1415926535/180));
	cout << setprecision(18) << s << "\n" << l << "\n" << h << "\n";
	return 0;
}