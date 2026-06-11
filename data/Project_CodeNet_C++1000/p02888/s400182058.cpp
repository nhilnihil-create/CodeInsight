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

int f(const vector<int>& v, int n, int index) {
	int b = index, e = v.size() - 1;
	if (index >= v.size() || v[index] >= n) return 0;
	while (b < e) {
		int m = (b + e) / 2 + 1;
		if (v[m] >= n) {
			e = m - 1;
		} else {
			b = m;
		}
	}
	return b - index + 1;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			res += f(v, v[i] + v[j], j + 1);
		}
	}
	cout << res << endl;
}
