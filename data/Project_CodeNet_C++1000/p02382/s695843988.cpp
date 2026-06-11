#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> y[i];
	}

	long double p1 = 0;
	for (int i = 0; i < n; i++)
	{
		p1 += fabs(x[i] - y[i]);
	}
	cout << fixed << p1 << endl;

	long double p2 = 0;
	for (int i = 0; i < n; i++)
	{
		p2 += pow(fabs(x[i] - y[i]), 2);
	}
	p2 = sqrt(p2);
	cout << fixed << p2 << endl;

	long double p3 = 0;
	for (int i = 0; i < n; i++)
	{
		p3 += pow(fabs(x[i] - y[i]), 3);
	}
	p3 = pow(p3, 1.0/3);
	cout << fixed << p3 << endl;

	vector<long double > dist(n);
	for (int i = 0; i < n; i++)
	{
		dist[i] = fabs(x[i] - y[i]);
	}

	long double maxele = *max_element(dist.begin(), dist.end());

	cout << maxele << endl;

	return 0;
}