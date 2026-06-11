#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>H(N);
	for (int n = 0; n < N; ++n) {
		cin >> H[n];
	}
	for (int n = 0;n<N;++n) {
		if (0 == n) {
			H[n]--;
			continue;
		}
		if (H[n] < H[n - 1]) {
			cout << "No" << endl;
			return 0;
		}
		if (H[n] > H[n-1]) {
			H[n]--;
		}
	}
	cout << "Yes" <<endl;
	return 0;
}
