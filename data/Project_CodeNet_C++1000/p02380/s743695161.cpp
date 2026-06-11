#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define rep2(x,from,to) for(int x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
int main() {
	double a, b;
	int x;
	cin >> a >> b >> x;
	double rad = acos(-1) * x / 180.0;
	double s = sin(rad) * a * b / 2.0;
	printf("%.10lf\n", s);
	double c = sqrt(pow(a, 2.0) + pow(b, 2.0) - 2.0 * a * b * cos(rad));
	printf("%.10lf\n", a + b + c);
	printf("%.10lf\n", 2.0 * s / a);
	return 0;
}