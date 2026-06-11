#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> vec(n);
	for (auto& e : vec) {
		cin >> e;
	}

	sort(vec.begin(), vec.end());
	int ans = 0;

	for (int a = 0; a < n - 2; a++) {
		for (int b = a + 1; b < n - 1; b++) {
			ans += (lower_bound(vec.begin(), vec.end(), vec[a] + vec[b]) - vec.begin()) - (b + 1);
		}
	}
	cout << ans << endl;
}