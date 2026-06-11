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

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector<int> res(n + 1, 0);
	for (int i = n; i >= 1; i--) {
		int c = 0;
		for (int j = 1; i * j <= n; j++) {
			c += res[i * j];
		}
		if (c % 2 != a[i]) {
			res[i]++;
		}
	}
	int m = accumulate(res.begin(), res.end(), 0);
	cout << m << endl;
	for (int i = 1; i <= n; i++) {
		if (res[i] == 1) {
			cout << i << endl;
		}
	}
}
