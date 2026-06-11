#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N; 
	int l = 0;
	int r = 0;
	int ans = 1001001001;
	vector<int>W(N);
	for (int n = 0; n < N; ++n) {
		cin >> W[n];
		l += W[n];
	}
	ans = min(ans, abs(l - r));
	for (int n = 0; n < N; ++n) {
		l -= W[n];
		r += W[n];
		ans = min(ans, abs(l - r));

	}
	cout << ans << endl;
	return 0;
}