#include "bits/stdc++.h"
using namespace std;

int main() {
	long long K, Q;
	cin >> K >> Q;
	vector<long long> D(K);
	for (int i = 0; i < K; i++) cin >> D[i];
	for (int h = 0; h < Q; h++) {
		long long N, X, M;
		cin >> N >> X >> M;
		vector<long long> E(K);
		for (int i = 0; i < K; i++) E[i] = (D[i] + M - 1) % M + 1;
		long long COUNT = X % M, SUM = 0;
		for (int i = 0; i < K; i++) SUM += E[i];
		N--;
		COUNT += SUM * (N / K);
		for (int i = 0; i < N % K; i++) COUNT += E[i];
		cout << N - COUNT / M << endl;
	}
}