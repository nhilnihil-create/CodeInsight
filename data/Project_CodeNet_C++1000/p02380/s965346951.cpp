#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

double a,b,C;
int main(){
	cin >> a >> b >> C;
	double S = a/2*b*sin(C/180*M_PI);
	double c = sqrt(a*a+b*b-2*a*b*cos(C/180*M_PI));
	double L = (a+b+c);
	double h = 2*S/a;
	printf("%.6f\n",S);
	printf("%.6f\n",L);
	printf("%.6f\n",h);
}
