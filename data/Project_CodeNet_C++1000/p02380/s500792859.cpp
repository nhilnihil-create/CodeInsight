#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
	double a, b, C, PI=3.1415926535;
	cin >> a >> b >> C;
	cout << fixed << setprecision(10) << a*b*sin(C*PI/180)/2.0 << endl;
	cout << fixed << setprecision(10) << a + b + sqrt( pow(a*sin(C*PI/180),2) + pow(b-a*cos(C*PI/180),2) ) << endl;
	cout << fixed << setprecision(10) << b*sin(C*PI/180) << endl;
	return 0;
}