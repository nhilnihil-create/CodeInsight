#include "bits/stdc++.h"

using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int>P(N);
	for (int n = 0;n<N;++n) {
		cin >> P[n];
	}
	int ans = 1;
	int mini = P[0];
	for (int n = 1;n < N;++n) {
		if (mini >= P[n]) {
			ans++;
		}
		mini = min(mini,P[n]);
	}
	cout << ans <<  endl;
	return 0;
}
