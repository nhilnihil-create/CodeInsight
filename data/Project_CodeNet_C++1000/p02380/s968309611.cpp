#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
	double a, b, C, h, S, L, rad;
	cin >> a >> b >> C;
	rad = M_PI * C / 180.0;
	h = b*sin(rad);
	S = a*h/2;
	L = a + b + sqrt(a*a + b*b - 2*a*b*cos(rad));
	printf("%.8f\n%.8f\n%.8f\n", S, L, h);
	return 0;
}