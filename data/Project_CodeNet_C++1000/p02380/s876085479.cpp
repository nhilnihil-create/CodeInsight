#include <math.h>
#include <iostream>
using namespace std;

#define PI 3.14159265

int main()
{
	long double a, b, C;
	long double S, L, h;
	cin >> a >> b >> C;
	cout << fixed << a*b*sin(C*(PI/180)) / 2 << endl;
	cout << fixed << a + b + sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(C*(PI / 180))) << endl;
	cout << fixed << b * sin(C*(PI / 180)) << endl;
	return 0;
}