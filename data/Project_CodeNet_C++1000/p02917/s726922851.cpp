#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> B(N-1);
	for (int n = 0; n <N-1; ++n) {
		cin >> B[n];
	}
	int ans = 0;	
	for (int n = 0; n < N - 2; ++n) {
		ans += min(B[n],B[n+1]);
	}
	ans += B[0];
	ans += B[N - 2];
	cout << ans <<endl;
	return 0;
}
