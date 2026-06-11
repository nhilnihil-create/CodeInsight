#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >>N;
	int ans = 0;
	vector<int>D(N);
	for (int n = 0;n<N;++n) {
		cin >> D[n];
		ans += D[n];
	}
	ans *= ans;
	for (int n = 0; n < N; ++n) {
		ans -= D[n]*D[n];
	}
	ans /= 2;
	cout << ans <<endl;
	return 0;
}