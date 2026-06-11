#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N; 
	vector<int>P(N);
	for (int n = 0;n<N;++n) {
		cin >> P[n];
	}
	int ans = 0;
	for (int n = 1;n<N-1;++n) {
		if (P[n-1]<P[n] && P[n]<P[n+1]) {
			ans++;
		}
		if (P[n - 1] > P[n] && P[n] > P[n + 1]) {
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}