#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	int x[n] = {};
	int y[n] = {};

	for (int i = 0; i < n; i++){
		cin >> x[i];
	}

	for (int i = 0; i < n; i++){
		cin >> y[i];
	}

	double d1 = 0, d2 = 0, d3 = 0, dm = 0;
	for (int i = 0; i < n; i++){
		d1 += fabs(x[i] - y[i]);
	}

	for (int i = 0; i < n; i++){
		d2 += pow(x[i] - y[i], 2);
	}
	d2 = sqrt(d2);

	for (int i = 0; i < n; i++){
		d3 += pow(fabs(x[i] - y[i]), 3);
	}

	d3 = pow(d3, 1.0/3.0);

	for (int i = 0; i < n; i++){
		if (dm < fabs(x[i] - y[i])) dm = fabs(x[i] - y[i]);
	}

	printf("%lf\n%lf\n%lf\n%lf\n", d1, d2, d3, dm);

	return 0;

}
