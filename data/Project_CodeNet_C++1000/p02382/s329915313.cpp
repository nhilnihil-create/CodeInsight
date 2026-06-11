#include <iostream>
#include <math.h>
using namespace std;

int main() {
	double n;
	cin >> n;
	double x[100] = {0};
	double y[100] = {0};

	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> y[i];
	}

	double p1 = 0;
	for (int i = 0; i < n; i++)
	{
		p1 += fabs(x[i] - y[i]);
	}
	cout <<fixed<< p1 << endl;

	double p2 = 0;

	for (int i = 0; i < n; i++)
	{
		p2 += (x[i] - y[i])*(x[i] - y[i]);
	}
	cout <<fixed<< sqrt(p2) << endl;

	double p3 = 0;

	for (int i = 0; i < n; i++)
	{
		p3 += fabs((x[i] - y[i])*(x[i] - y[i])*(x[i] - y[i]));
	}
	cout << fixed << pow(p3, 1.0/3) << endl;

	double p0 = 0;
	for (int i = 0; i < n; i++)
	{
		int v = fabs(x[i] - y[i]);
			if (v > p0)
				p0 = v;
	}
	cout <<fixed<< p0 << endl;

	return 0;
}