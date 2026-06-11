#include <bits/stdc++.h>
using namespace std;

int main()
{
	pair<double, double> x, y;
	cin >> x.first >> x.second >> y.first >> y.second;

	cout << fixed <<  sqrt(pow((y.first - x.first), 2) + pow((y.second - x.second), 2)) << endl;
	return 0;
}