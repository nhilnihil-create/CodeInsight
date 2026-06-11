#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const long long INF = 1LL << 61;
const int MOD = 2019;

int main() {
	int N; cin >> N;
	vector<int> A(N);
	rep(i, N)cin >> A[i];
	vector<long long> d(N, 0);
	rep(i, N) {
		if (i % 2 == 0)d[0] += A[i];
		else d[0] -= A[i];
	}
	//cout << d[0] << endl;
	rep(i, N - 1) {
		d[i + 1] = (long long)2 * A[i] - d[i];
	}
	rep(i, N)cout << d[i] << " ";
}