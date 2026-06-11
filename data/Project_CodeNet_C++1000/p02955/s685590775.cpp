#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

long long int f(int n, const vector<int>& v) {
	long long int res = 0;
	int s = 0;
	vector<int> nums;
	for (auto num : v) {
		int m1 = abs(num % n), m2 = n - abs(num % n);
		s += m1;
		nums.push_back(m1);
	}
	sort(nums.begin(), nums.end());
	return accumulate(nums.begin(), nums.end() - s / n, 0);
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int s = accumulate(v.begin(), v.end(), 0);
	int res = 1;
	for (int i = 1; i * i <= s; i++) {
		if (s % i == 0) {
			long long int ret = f(i, v);
			if (ret <= k) {
				res = max(res, i);
			}
			if (s != i * i) {
				ret = f(s / i, v);
				if (ret <= k) {
					res = max(res, s / i);
				}
			}
		}
	}
	cout << res << endl;
}
