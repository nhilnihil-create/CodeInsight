#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const double PI = 3.14159265359;

double f(double a, double b, double rad) {
	if (b * tan(PI / 2 - rad) <= a) {
		return a * b * b * tan(PI / 2 - rad) / 2.0;
	}
	else {
		return a * a * b - a * a * a * tan(rad) / 2.0;
	}
}

int main() {
	double a, b, x;
	cin >> a >> b >> x;
	double left = 0.0, right = 90.0;
	while (right - left >= 0.0000000001) {
		double mid = (left + right) / 2.0;
		double rad = PI / 180.0 * mid;
		if (x < f(a, b, rad)) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	printf("%.10f\n", right);
	return 0;
}