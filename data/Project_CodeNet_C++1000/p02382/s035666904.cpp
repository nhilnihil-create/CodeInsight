#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>	

#define PI 3.14159265359
using namespace std;

int main(){
	int n;
	double dist;
	cin >> n;
	vector<double> x(n), y(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < n; i++) cin >> y[i];
	dist = 0;
	for (int i = 0; i < n; i++) dist += abs(x[i] - y[i]);
	cout << fixed << setprecision(9) << dist << endl;
	dist = 0;
	for (int i = 0; i < n; i++) dist += (x[i] - y[i]) * (x[i] - y[i]);
	cout << fixed << setprecision(9) << sqrt(dist) << endl;
	dist = 0;
	for (int i = 0; i < n; i++) dist += abs(pow(x[i] - y[i], 3));
	cout << fixed << setprecision(9) << pow(dist, 1.0 / 3.0) << endl;
	dist = abs(x[0] - y[0]);
	for (int i = 1; i < n; i++) dist = max(dist, abs(x[i] - y[i]));
	cout << fixed << setprecision(9) << dist << endl;
}