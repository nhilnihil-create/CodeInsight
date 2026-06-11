#include <bits/stdc++.h>
using namespace std;

const double epsilon = 1e-9;
const long double pi = 3.1415926535;
double a, b, x;

bool spilled(double theta) {
	double h1 = a * sin(theta), h2 = b * sin(pi / 2 - theta);
	if (h1 > h2) {
		return (x > (a * b * b * tan(pi / 2 - theta) / 2));
	}
	else {
		return (x > ((a * a * b) - (a * a * a * tan(theta)) / 2));
	}
}

void bs() {
	long double l = 0, r = pi / 2, mid;
	while (abs(l - r) > epsilon) {
		mid = (l + r) / 2;
		if (spilled(mid))
			r = mid;
		else
			l = mid;
	}
	cout << setprecision(9) << l * 180 / pi << "\n";
}

int main() {
	cin >> a >> b >> x;
	bs();
	// spilled(45.0);
}
