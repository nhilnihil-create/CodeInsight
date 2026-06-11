#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
	double a, b, c,d, S, L, h;
	cin >> a >> b >> c;
	c = c / 180 * 3.1415926535;
	h = b * sin(c);
	S = a * h * 1 / 2;
	L = pow(a, 2) + pow(b, 2)-2*a*b*cos(c);
	L = sqrt(L) + a + b;
	printf("%f\n%f\n%f\n", S, L, h);
	
	return 0;
}
