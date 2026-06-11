#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>L(N);
	for (int n = 0; n < N; ++n) {
		cin >> L[n];
	};
	sort(L.begin(), L.end());
	int ans = 0;
	for (int n = 0; n < N; ++n) {
		for (int m = n + 1; m < N; ++m) {
			int num = lower_bound(L.begin(), L.end(), L[n] + L[m]) - L.begin();
			ans += max(0, (num - (m+1)));
		}
	}
	cout << ans << endl;
	return 0;
}
