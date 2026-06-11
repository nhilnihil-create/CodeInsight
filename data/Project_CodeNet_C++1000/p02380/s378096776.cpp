#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main() {
	double a, b, C;
	
	cin >> a;
	cin >> b;
	cin >> C;
	
	//cout << 0.5 * a * b * sin(M_PI*C/180.0) << endl;
	//cout << a + b + sqrt(a*a+b*b-2*a*b*cos(M_PI*C/180.0)) << endl;
	//cout << b * sin(M_PI*C/180.0) << endl;
	
	printf("%f \n", 0.5 * a * b * sin(M_PI*C/180.0));
	printf("%f \n", a + b + sqrt(a*a+b*b-2*a*b*cos(M_PI*C/180.0)));
	printf("%f \n", b * sin(M_PI*C/180.0));
	
	return 0;
}