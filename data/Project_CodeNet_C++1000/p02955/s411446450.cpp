#include "bits/stdc++.h"
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std; 
typedef pair<int, int> P;

int main() {
	long long N, K;
	cin >> N >> K;
	vector<long long>A(N);
	long long sum = 0;
	for (int n = 0;n<N;++n) {
		cin >> A[n];
		sum += (long long)A[n];
	}
	set<long long>B;
	for (int i = 1;i*i<sum; ++i) {
		if (0 == sum%i) {
			B.insert(i);
			B.insert(sum/i);
		}
	}
	long long ans = 0;
	
	for (auto itr = B.begin();itr != B.end();itr++) {
		long long nowans = 1e18;
		long long now = *itr;
		vector<long long>C(N);
		for (int n = 0; n < N; ++n) {
			C[n] = A[n] % now;
		}	
		sort(C.begin(), C.end());
		long long l = 0;
		long long r = 0;
		vector<long long>L(N);
		vector<long long>R(N);
		for (int n = 0; n < C.size(); ++n) {
			L[n] = C[n];
			R[n] = now - C[n];
			l += L[n]; 
		}
		nowans = min(nowans, max(l, r));
		for (int n = 0; n < C.size(); ++n) {
			l -= L[C.size()-1-n];
			r += R[C.size() - 1-n];
			nowans = min(nowans, max(l, r));
		}
		if (K >= nowans) {
			ans = max(ans, now);
		}
	}
	cout << ans << endl;
	return 0;
}