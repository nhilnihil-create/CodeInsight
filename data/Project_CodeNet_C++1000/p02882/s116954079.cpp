#include <iostream>
#include <math.h>
using namespace std;
int main(void){
	double a, b, x;
	cin >> a >> b >> x;
	double r = x<= (b*a*a)/2.0? atan(2.0*x/(a*b*b)) : atan(a*a/(2.0*(a*b-x/a)));
	cout.precision(11);
	cout << 90.0-r*180.0/acos(-1.0) << endl;
}