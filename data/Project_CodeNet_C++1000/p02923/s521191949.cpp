#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> H(N);
	for (int n = 0; n < N; ++n) {
		cin >> H[n];
	}
	int ans = 0;
	int now = 0;
	for (int n = 0; n < N - 1; ++n) {
		if (H[n] >= H[n + 1]) {
			++now;
			ans = max(ans, now);
		}
		else {
			now = 0;
		}
	}
	cout << ans <<endl;
	return 0;
}
