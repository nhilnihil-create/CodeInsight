#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<double> x(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	vector<double> y(n);
	for (int i = 0; i < n; i++)
	{
		cin >> y[i];
	}
	vector<double> d(4, 0);
	for (int i = 0; i < n; i++)
	{
		d[0] += abs(x[i] - y[i]);
		d[1] += pow(abs(x[i] - y[i]), 2);
		d[2] += pow(abs(x[i] - y[i]), 3);
		d[3] = max(abs(x[i] - y[i]), d[3]);
	}
	cout << fixed << setprecision(6) << d[0] << endl;
	cout << pow(d[1], 1 / 2.0) << endl;
	cout << pow(d[2], 1 / 3.0) << endl;
	cout << d[3] << endl;
}
