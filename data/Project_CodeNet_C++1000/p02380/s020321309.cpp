#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
using namespace std;

double degreeToRad(double degree){
	double rad =M_PI*degree / 180.0;
	return rad;
}

int main()
{
	double a,b,C,c;
	double S,L,h;
	cin>>a>>b>>C;
	C = degreeToRad(C);
	S = 0.5*a*b*sin(C);
	h = b*sin(C);
	c = sqrt(a*a + b*b - 2.0*a*b*cos(C));
	L = a + b + c;

	printf("%0.5lf\n%0.5lf\n%0.5lf\n",S,L,h);
	return 0;
}