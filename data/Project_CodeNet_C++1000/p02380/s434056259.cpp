#include <bits/stdc++.h>
#define PI 3.141592653589793
using namespace std;

int main() {
	// your code goes here
	int a,b,C;
	cin >> a >> b >> C;
	double c = C/180.0*PI;
	double S = a*b*sin(c)/2.0;
	double L = a+b+sqrt(a*a+b*b-2*a*b*cos(c));
	double h = b*sin(c);
	printf("%.6lf\n%.6lf\n%.6lf\n",S,L,h);
	return 0;
}
