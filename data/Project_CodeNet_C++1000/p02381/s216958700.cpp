#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int n;
	while ( cin >> n, n ) {
		double v[1000];
		for (int i = 0; i < n; ++i) cin >> v[i];

		double m = 0;
		for (int i = 0; i < n; ++i) m += v[i];
		m /= n;

		double s = 0;
		for (int i = 0; i < n; ++i) s += (v[i] - m) * (v[i] - m);
		s = sqrt(s / n);

		printf("%.10f\n", s);
	}
}