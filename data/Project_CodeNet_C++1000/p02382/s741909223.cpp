#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long > vll;
typedef vector< vi > vvi;
int main() {
	double n, p, D1 = 0, D2 = 0, D3 = 0, Dinf = 0;
	cin >> n;
	vector<double>x(n);
	vector<double>y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}
	for (int i = 0; i < n; i++) {
		if (x[i] < y[i]) {
			D1 += y[i] - x[i];
			D3 += pow(y[i] - x[i], 3);
		}
		else {
			D1 += x[i] - y[i];
			D3 += pow(x[i] - y[i], 3);
		}
		D2 += pow(x[i] - y[i], 2);
	}
	Dinf = fabs(x[0] - y[0]);
	for (int i = 0; i < n; i++) {
		if (Dinf < fabs(x[i] - y[i])) {
			Dinf = fabs(x[i] - y[i]);
		}
	}
	D2 = pow(D2, 0.5);
	D3 = pow(D3, 1.0 / 3.0);
	printf("%.6lf\n", D1);
	printf("%.6lf\n", D2);
	printf("%.6lf\n", D3);
	printf("%.6lf\n", Dinf);
}