#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
	int n, t;
	double d1 = 0;
	double d2 = 0;
	double d3 = 0;
	double d4 = 0;
	vector<int> x;
	vector<int> y;

	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		cin >> t;

		x.push_back(t);
	}
		
	for (int i = 0; i < n; i++)
	{
		cin >> t;

		y.push_back(t);
	}

	for (int i = 0; i < n; i++)
	{
		d1 += abs(x[i] - y[i]);
	}

	for (int i = 0; i < n; i++)
	{
		d2 += (abs(x[i] - y[i]) * abs(x[i] - y[i]));
	}

	d2 = sqrt(d2);

	for (int i = 0; i < n; i++)
	{
		d3 += abs(x[i] - y[i]) * abs(x[i] - y[i]) * abs(x[i] - y[i]);
	}

	d3 = pow(d3, 1.0 / 3);

	d4 = -1;
	double k;

	for (int i = 0; i < n; i++)
	{
		k = abs(x[i] - y[i]);
		
		if (k > d4) d4 = k;
	}

	cout.precision(6);

	cout << fixed << d1 << "\n";
	cout << fixed << d2 << "\n";
	cout << fixed << d3 << "\n";
	cout << fixed << d4 << "\n";

	return 0;
}
