//#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	long long int ans = 1e9;
	for (int i = x[0]; i <= x[n - 1]; i++) {
		long long int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += pow(i - x[j], 2);
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}