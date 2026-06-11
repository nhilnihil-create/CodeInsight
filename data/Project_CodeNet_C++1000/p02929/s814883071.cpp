#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	const Int MOD = 1e9 + 7;
	int N;
	cin >> N;
	string s;
	cin >> s;

	vector<Int> R(2 * N, 0);
	vector<int> L;
	Int cnt = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (cnt < 0) {
			cout << 0 << endl;
			return 0;
		}

		if (s[i] == 'B') {
			if (cnt % 2 == 0) {
				L.push_back(i);
				++cnt;
			} else {
				R[i] = 1;
				--cnt;
			}
		} else {
			if (cnt % 2 == 0) {
				R[i] = 1;
				--cnt;
			} else {
				L.push_back(i);
				++cnt;
			}
		}
	}
	for (int i = 2*N - 2; i >= 0; --i) { R[i] += R[i + 1]; }
	
	Int ans = (cnt == 0 ? 1 : 0);
	for (Int i = 1; i <= N; ++i) { (ans *= i) %= MOD; }

	int sz = L.size();
	for (int i = 0; i < L.size(); ++i) {
		Int x = R[L[sz - 1 - i]] - i;
		(ans *= x) %= MOD;
	}
	cout << ans % MOD << endl;

	return 0;
}
