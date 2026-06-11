//#include "bits/stdc++.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
// #include <map>
// #include <string>
// #include <algorithm>
// #include <numeric>
// #include <limits>

using namespace std;

void measure(int n, vector<int> x, vector<int> y) {
	double d1 = 0, d2 = 0, d3 = 0, di = 0;
	int d;
	for (int i = 0; i < n; i++) {
		if (x[i] < y[i]) {
			d = y[i] - x[i];
		} else {
			d = x[i] - y[i];
		}
		d1 += d;
		d2 += pow(d, 2);
		d3 += pow(d, 3);
		if (di < d) {
			di = d;
		}
	}
	cout << fixed << setprecision(6);
	cout << d1 << endl;
	cout << pow(d2, double(1)/2) << endl;
	cout << pow(d3, double(1)/3) << endl;
	cout << di << endl;
}

int main() {
	int n;
	cin >> n;

	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}

	measure(n, x, y);
	// std::cout << "\e[38;5;0m\e[48;5;40m --- end ---  \e[m" << std::endl; // debug
	return 0;
}

