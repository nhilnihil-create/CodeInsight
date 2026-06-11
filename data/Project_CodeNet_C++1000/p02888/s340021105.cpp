#include<bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> L(N);
	for (int i = 0; i < N; ++i) cin >> L[i];

	sort(L.begin(), L.end());
	long long ans = 0;
	for (int i = 0; i < N; i++) for (int j = i + 1; j < N; ++j) {
		int lbm1 = lower_bound(L.begin(), L.end(), L[i] + L[j]) - L.begin() - 1;
		//cout << L[i] + L[j] << endl;
		//cout << lbm1 << endl;
		ans += max(0, lbm1 - j);
	}

	cout << ans << endl;
	return 0;
}