#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long>A(N);
	vector<long long>C(N);
	for (int n = 0;n<N;++n) {
		long long  m = 0;
		cin >> m;
		m--;
		A[n] = m;
		C[m]++;
	}
	long long ans = 0;
	for (int n = 0;n<N;++n) {
		ans += C[n] * (C[n] - 1) / 2;
	}
	for (int n = 0;n<N;++n) {
		cout <<ans-(C[A[n]]-1)<<endl;
	}
	return 0;
}