#include "bits/stdc++.h"
using namespace std;
int dp[3005][3005];
int main() {
	long long N,K;
	cin >> N >> K;
	vector<long long>A(N); 
	vector<long long>F(N);
	for (int n = 0;n<N;++n) {
		cin >> A[n];
	}
	for (int n = 0; n < N; ++n) {
		cin >> F[n];
	}  
	sort(A.begin(), A.end());
	sort(F.rbegin(), F.rend());
	long long l = -1;
	long long r = 1000000000000;
	//[l,r)
	while (l + 1 < r) {
		long long c = (l + r) / 2;
		long long tmp = 0;
		for (int n = 0; n < N; ++n) {
			tmp += max(0ll, A[n] - c / F[n]);
		}
		if (tmp > K) {
			l = c;
		}
		else {
			r = c;
		}
	}
	cout << r << endl;
	return 0;
}