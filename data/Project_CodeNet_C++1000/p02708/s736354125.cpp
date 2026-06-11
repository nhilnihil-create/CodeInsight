#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, K; cin >> N >> K;
	vector<long long>sum(N + 2);
	sum.at(0) = 0;
	for (long long i = 0; i <= N; i++) {
		sum.at(i + 1) = sum.at(i) + i;
	}
	long long ans = 0;
	for (long long j = K; j <= N + 1; j++) {
		ans += sum.at(N + 1) - sum.at(N + 1 - j) - sum.at(j) + 1;
	}
	cout << ans % (1000000007) << endl;
}