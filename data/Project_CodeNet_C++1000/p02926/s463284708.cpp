
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
#include <cstdint>
using namespace std;
using LL = long long;

int N;
vector<complex<double>>vec;

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) {}
		else {
			vec.push_back(complex<double>(x, y));
		}
	}
	N = vec.size();
	double ans = 0;
	sort(vec.begin(), vec.end(), [](const complex<double>& c1, const complex<double>& c2) {
		return arg(c1) < arg(c2);
		});
	for (int i = 0; i < N; ++i) {
		vec.push_back(vec[i]);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = i; j <= i + N; ++j) {
			complex<double>sum(0, 0);
			for (int k = i; k < j; ++k) {
				sum += vec[k];
			}
			ans = max(ans, abs(sum));
		}
	}
	cout.precision(20);
	cout << fixed;
	cout << ans << endl;
	return 0;
}