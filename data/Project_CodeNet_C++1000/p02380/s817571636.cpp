#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
int main(){

	double a, b, C, x, S, L, h;
	cin >> a >> b >> C;

	C = C*3.1415926535 / 180;

	//高さ h
	h = b*sin(C);

	//面積 S
	S = a*h / 2;

	//周の長さ L
	x = pow(a,2)+pow(b,2) - 2 * a*b*cos(C);
	x = sqrt(x);
	L = a + b + x;

	printf("%f\n%f\n%f\n", S, L, h);

	return 0;
}
