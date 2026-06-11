#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
using namespace std;

int main(void){
	int n;
	int *x, *y;
	double p1, p2, p3, pi;

	cin >> n;
	x = new int[n];
	y = new int[n];

	for (int i = 0; i < n; i++){
		cin >> x[i];
	}
	for (int i = 0; i < n; i++){
		cin >> y[i];
	}

	p1 = p2 = p3 = pi = 0;
	for (int i = 0; i < n; i++){
		p1 += abs(x[i] - y[i]);
		p2 += abs((x[i] - y[i])*(x[i] - y[i]));
		p3 += abs((x[i] - y[i])*(x[i] - y[i])*(x[i] - y[i]));
		if (pi < abs((x[i] - y[i]))){
			pi = abs((x[i] - y[i]));
		}
	}

	p2 = sqrt(p2);

	double temp = pow(p3, 1. / 3);
	if (temp == 0)
		p3 = 0.0;
	else
		p3 = (2 * temp + p3 / temp / temp) / 3;

	cout << fixed << setprecision(10) << p1 << "\n" << p2 << "\n" << p3 << "\n" << pi << "\n";

	delete[] x, y;
	return 0;
}