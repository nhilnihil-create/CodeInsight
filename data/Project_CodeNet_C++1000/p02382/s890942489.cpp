#include <cstdio>
#include <cmath>
#include <iostream>
#define N 100
using namespace std;
main () {
	int n;
	double x[N], y[N];
	cin >> n;
	for (int i=0; i<n; i++) cin >> x[i];
	for (int i=0; i<n; i++) cin >> y[i];

	double d[4] = {};
	for (int k=0; k<3; k++) {
		for (int i=0; i<n; i++)
			d[k] += pow(abs(x[i]-y[i]), k+1);
		d[k] = pow(d[k], 1.0/(k+1));
	}
	for (int i=0; i<n; i++)
		d[3] = max(d[3], abs(x[i]-y[i]));
	
	for (int k=0; k<4; k++) printf("%.6f\n", d[k]);
}