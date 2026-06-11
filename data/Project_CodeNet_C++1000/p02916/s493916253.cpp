#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	vector<int>B(N);
	vector<int>C(N - 1); 
	vector<int>D;
	for (int n = 0 ;n<N;++n) {
		cin >> A[n];
		if (0 != n) {
			if (A[n]-1 == A[n-1]) {
				D.push_back(A[n-1]);
			}
		}
	}
	int ans = 0;	
	for (int n = 0; n < N; ++n) {
		cin >> B[n];
		ans += B[n];
	}	
	for (int n = 0; n < N - 1; ++n) {
		cin >> C[n];
	}	
	for (int n = 0; n < D.size(); ++n) {
		ans += C[D[n]-1];
	}
	cout << ans <<endl;
	return 0;
}