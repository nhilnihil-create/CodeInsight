#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const long long INF = 1LL << 61;

int main() {
	int N; cin >> N;
	vector<int> A(N);
	rep(i, N)cin >> A[i];

	double ans = 0;
	rep(i, N)ans += (double)1 / A[i];
	cout << fixed << setprecision(15) << 1/ans << endl;
}