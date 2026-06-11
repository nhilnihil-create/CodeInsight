#include<iostream>
#include<stdio.h>
#include<math.h>

#define PI 3.14159265f

using namespace std;


int main() {
	int a, b, C;
	double S, L, h;

	cin >> a >> b >> C;

	S = a*b*0.5*sin(C*PI / 180);
	L = a + b + sqrt(a*a + b*b - 2 * a*b*cos(C*PI / 180));
	h = b*sin(C*PI / 180);

	printf("%f %f %f\n", S, L, h);

	return 0;
}