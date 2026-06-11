#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main()
{
	int n, x[1000] = {}, y[1000] = {}, t;
	double p1 = 0, p2 = 0, p3 = 0, pi = 0;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int j = 0; j < n; j++) cin >> y[j];

	for (int k = 0; k < n; k++) {
		t = abs(x[k] - y[k]);
		p1 += t;
		p2 += t * t;
		p3 += t * t * t;
		if (pi < t) pi = t;
	}

	cout << fixed << p1 << endl << sqrt(p2) << endl << cbrt(p3) << endl << pi << endl;

	return 0;
}