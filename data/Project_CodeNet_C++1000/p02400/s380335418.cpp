#include <iostream>
#include <stdio.h>
const double M_PI = 3.14159265359;
using namespace std;

int main()
{
	double r;
	double S,L;
	cin>>r;
	S = r*r*M_PI;
	L = 2.0*M_PI*r;
	printf("%12lf %12lf\n", S,L);
	return 0;
}