#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <tuple>
#include <functional>
#include <numeric>
#include <cmath>
#include <iomanip>
#include <map>
//#include "toollib.h"
#pragma warning (disable:4018)
#define INT_MAX 2147483647

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> b{ a[0] };
	for (int i = 0; i < n; i++) {
		if (a[i] > b.back()) b.push_back(a[i]);
		else {
			for (int j = 0; j < b.size(); j++) {
				if (b[j] >= a[i]) {
					b[j] = a[i];
					break;
				}
			}
		}
	}
	cout << b.size() << endl;
	return 0;
}