#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double call(int x[], int y[],int n,int i) {
	double D = 0.0;

	for (int k = 0; k < n; k++) {
		D += pow(fabs((x[k] - y[k])), i);
	}

	return pow(D, 1.0 / i);
}

int main() {
	int n, x[100], y[100], i;

	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (i = 0; i < n; i++) {
		cin >> y[i];
	}

	double max;
	
	for (i = 0; i < n; i++) {
		int xy = x[i] - y[i];

		xy = fabs(xy);

		if (i == 0)
			max = 1.0*xy;
		else
			if (max < xy)
				max = xy;
	}

	for (i = 1; i <= 3; i++) {
		printf("%lf\n", call(x, y, n, i));
	}
	printf("%lf\n", max);

	return 0;
}