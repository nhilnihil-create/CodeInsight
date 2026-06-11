#include "bits/stdc++.h"
using namespace std; 

int main() {
	int N;
	cin >> N;
	vector<pair<long long, long long>>A(N);
	for (long long n = 0;n<N; ++n) {
		long long m;
		cin >> m;
		A.push_back(make_pair(m,n + 1));
	}

	sort(A.rbegin(),A.rend()); 
	const int MX = 2005;
	vector<vector<long long >> DP(N + 10, vector<long long>(N + 10));
	for (int n = 0;n <= N;++n) {
		for (int m = 0;m <= n;++m) {
			long long fir = A[n].first;
			long long sec = A[n].second;
			//今 m,n-mを見ている
			DP[m + 1][n - m] = max(DP[m + 1][n - m],DP[m][n-m] + (sec- m -1) *fir);
			DP[m][n - m + 1] = max(DP[m][n - m + 1],DP[m][n-m] + (N-(n-m)-sec)*fir);
		}
	}
	long long ans = 0;
	for (int n = 0;n <= N;++n) {
		ans = max(ans ,DP[N-n][n]);
	}
	cout << ans <<endl;
	return 0;
}