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

void std_dev(int n, vector<int> s) {
	double sum = 0, mean, std_d;
	for (auto x : s) {
		sum += x;
	}
	mean = sum / n;
	sum = 0;
	for (auto x : s) {
		sum += pow(mean - x, 2);
	}
	std_d = sqrt(sum / n);
	cout << fixed << setprecision(6);
	cout << std_d << endl;
}

int main() {
	while (1) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}

		vector<int> s(n);
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			s[i] = tmp;
		}

		std_dev(n, s);
	}
	// std::cout << "\e[38;5;0m\e[48;5;40m --- end ---  \e[m" << std::endl; // debug
	return 0;
}

