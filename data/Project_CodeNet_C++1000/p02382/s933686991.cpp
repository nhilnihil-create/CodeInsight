#include <vector>
#include <iostream>
#include <math.h>

using namespace std;


int main() {

	int n,tmp;
	vector<double> x;
	double y, d1 = 0, d2 = 0, d3 = 0, di = 0;
	cout.precision(15);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		x.push_back(tmp);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> y;
		d1 += fabs(x[i] - y);
		d2 += pow(fabs(x[i] - y), 2);
		d3 += pow(fabs(x[i] - y), 3);
		if (di < fabs(x[i] - y)) di = fabs(x[i] - y);
	}
	cout << d1 << endl;
	cout << sqrt(d2) << endl;
	cout << pow(d3, (1.0 / 3.0)) << endl;
	cout << di << endl;

	return 0;
}