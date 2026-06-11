#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	//S
	cout << fixed << a*(b*sin((c*M_PI)/180)) /2.0<< endl;
	//L
	cout << fixed << a+b+sqrt(a*a+b*b-2*a*b*cos((c*M_PI) / 180)) << endl;
	//h
	cout << fixed << b*sin((c*M_PI) / 180) << endl;

	return 0;
}