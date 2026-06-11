#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	double v;
	vector<double> x;
	vector<double> y;
	int i;

	i = 0;
	while(1) {
		if(i >= n) break;
		cin >> v;
		x.push_back(v);
		//printf("[%d] %lf ", i, v);
		i++;
	}

	i = 0;
	while(1) {
		if(i >= n) break;
		cin >> v;
		y.push_back(v);
		//printf("[%d] %lf ", i, v);
		i++;
	}

	// p = 1, 2, 3
	int p;
	double sum;
	double d;
	for(p = 1; p <= 3; p++) {
		sum = 0;
		for(i = 0; i < n; i++) {
			sum += pow(fabs(x[i] - y[i]), (double)p);
		}
		d = pow(sum, 1.0 / (double)p);
		printf("%lf\n", d);
	}

	// p = infinity
	double dd;
	d = fabs(x[0] - y[0]);
	for(i = 1; i < n; i++) {
		dd = fabs(x[i] - y[i]);
		if(d < dd) d = dd;
	}
	printf("%lf\n", d);
	return 0;
}