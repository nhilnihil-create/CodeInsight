#include <iostream>
#include <math.h>
#include <cmath>
#include <stdio.h>
#define   pi   3.1415926535
using namespace std;

int main(){
	double a, b, C, S, L, h, cs, cc;

	cin>>a>>b>>C;
	C = C * pi / 180;
	cs = sin(C);
	cc = cos(C);

	S = a * b * cs / 2;
	L = a + b + sqrt(a*a + b*b - 2*a*b*cc);
	h = b * cs;

	printf("%.8lf\n%.8lf\n%.8lf\n", S, L, h);

	return 0;
}