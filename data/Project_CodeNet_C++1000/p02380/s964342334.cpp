#include <iostream>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;
signed main() {
	double a, b, c, d, h, t;
	cin >> a >> b >> t;
	t = t / 180 * 3.14159265358979;
	h = b * sin(t);
	d = a - sqrt(b * b - h * h);
	if (t > 3.14159265358979 / 2)d = a + sqrt(b * b - h * h);
	c = sqrt(d * d + h * h);
	printf("%.10f\n%.10f\n%.10f\n", a * h / 2, a + b + c, h);
	cin >> a;
}
