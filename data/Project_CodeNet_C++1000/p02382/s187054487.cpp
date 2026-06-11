#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

int n, x[100], y[100];


double minkowski_distance(double p)
{
	double sum = 0.0;
	for (int i = 0; i < n; i++)
		sum += pow(fabs(x[i] - y[i]), p);
	return pow(sum, 1.0 / p);
}
double minkowski_distance()
{
	double max = 0.0;
	for (int i = 0; i < n; i++) {
		if (fabs(x[i] - y[i]) > max)
			max = fabs(x[i] - y[i]);
	}
	return max;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}
	cout << fixed
		<< setprecision(8)
		<< minkowski_distance(1.0) << endl
		<< minkowski_distance(2.0) << endl
		<< minkowski_distance(3.0) << endl
		<< minkowski_distance() << endl;
	return 0;
}