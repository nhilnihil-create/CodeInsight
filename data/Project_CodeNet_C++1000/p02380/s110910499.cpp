#include<iostream>
#include <math.h>
#include <cstdio>

using namespace std;

int main(){
	double a, b, C, c, S, L, h;
	cin >> a >> b >> C;
	
	c = sqrt(pow(a, 2.0) + pow(b, 2.0) - 2.0 * a * b * cos(C * (M_PI / 180.0)));
	L = a + b + c;
	S = a * b * sin(C * (M_PI / 180.0)) / 2.0;
	h = b * sin(C * (M_PI / 180.0));
	
	printf("%.8f\n%.8f\n%.8f\n", S, L, h);
	
	return 0;
}