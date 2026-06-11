#include "bits/stdc++.h"
using namespace std;


int main() {
	int K,Q;
	cin >> K>> Q;
	vector<int>D(K);
	for (int n = 0;n<K;++n) {
		cin >> D[n];
	}
	vector<long long >N(Q); 
	vector<long long>X(Q); 
	vector<long long>M(Q);
	for (int n = 0;n<Q;++n) {
		cin >> N[n] >> X[n] >>M[n];
	}
	vector<long long>Ans(Q);
	for (int n = 0; n < Q; ++n) {
		vector<int>modD(K);
		for (int m = 0;m<K;++m) {
			modD[m] = D[m] % M[n];
		}
		long long num = X[n] % M[n];
		long long zero = 0;
		for (int m = 0; m < K; ++m) {
			long long count = (N[n]-1)/K;
			if (m < (N[n] - 1) % K) {
				count++;
			}
			num += count * modD[m % K];
			if (0 == modD[m % K]) {
				zero += count;
			}
		}
		long long kuriagari = (num)/M[n] -(X[n] % M[n])/M[n];
		Ans[n] = (N[n]-1) - zero - kuriagari;
	}
	for (int n = 0;n<Q;++n) {
		cout <<Ans[n]<<endl;
	}
	return 0;
}