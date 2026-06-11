#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
	double a, b, C, S, L, h;
	cin >> a >> b >> C;
	
	S = a*b*sin(M_PI*C/180)/2;
	L = sqrt(a*a+b*b-2*a*b*cos(M_PI*C/180)) + a + b;
	h = 2*S/a;
	
	printf("%f\n%f\n%f\n", S, L, h);
	
	return 0;
}
