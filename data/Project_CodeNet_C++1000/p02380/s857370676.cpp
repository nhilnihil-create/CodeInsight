#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
#define PI 3.14159265358979
using namespace std;

int main(){
	double a,b,c;
	cin >> a >> b >> c;
	double rad = c * PI / 180.0;
	double s = a * b / 2 * sin(rad);
	double l = a + b + sqrt(a * a + b * b -2 * a * b * cos(rad));
	double h = 2 * s / a;
	printf("%lf\n",s);
	printf("%lf\n",l);
	printf("%lf\n",h);
	return 0;
}