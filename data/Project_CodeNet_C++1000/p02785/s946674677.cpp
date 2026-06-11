#include "bits/stdc++.h"

using namespace std;
int main() {
	int N,K;
	cin >> N >> K;
	vector<long long>H(N);
	for (int n = 0;n<N;++n) {
		cin >> H[n];

	}
	sort(H.begin(),H.end());
	long long ans = 0;
	for (int n = 0;n < N - K;++n) {
		ans += H[n];
	}
	cout << ans <<  endl;
	return 0;
}
