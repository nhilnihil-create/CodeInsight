#include "bits/stdc++.h"
using namespace std;


int main() {
	int K,Q;
	cin >> K>> Q;
	vector<int>D(K);
	for (int n = 0;n<K;++n) {
		cin >> D[n];
	}
	for (int n = 0; n < Q; ++n) {
		long long N,X,M;
		cin >> N >> X >> M;
		vector<int>modD(K);
		for (int m = 0;m<K;++m) {
			modD[m] = D[m] % M;
		}
		long long num = X % M;
		long long zero = 0;
		for (int m = 0; m < K; ++m) {
			long long count = (N-1)/K;
			if (m < (N - 1) % K) {
				count++;
			}
			num += count * modD[m % K];
			if (0 == modD[m % K]) {
				zero += count;
			}
		}
		long long kuriagari = (num)/M -(X % M)/M;
		cout << (N - 1) - zero - kuriagari << endl;
	}
	return 0;
}