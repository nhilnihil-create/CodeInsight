#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main () {
	double a,b,c,s,l;
	cin >> a >> b >> c;
	s=a*b*sin(2*M_PI*c/360)/2;
	l=a+b+sqrt(a*a+b*b-2*a*b*cos(2*M_PI*c/360));
	cout  << setprecision(20) << s << endl << l <<  endl <<2*s/a << endl;
}