#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	const Int MOD = 1e9 + 7;
	int N;
	cin >> N;
	string s;
	cin >> s;

	vector<Int> R(2*N, 0);
	vector<int> L;
	Int cnt = 0;
	for (int i = 0; i < 2*N; ++i) {
		if (cnt < 0) {
			cout << 0 << endl;
			return 0;
		}

		if ((s[i] == 'B' && cnt % 2 == 0) || (s[i] == 'W' && cnt % 2 == 1)) {
			L.push_back(i);
			R[i] = -1;
			++cnt;
		} else {
			R[i] = 1;
			--cnt;
		}
	}
	for (int i = 2*N - 2; i >= 0; --i) { R[i] += R[i + 1]; }
	
	Int ans = (cnt == 0 ? 1 : 0);
	for (Int i = 1; i <= N; ++i) { (ans *= i) %= MOD; }

	for (int i = L.size() - 1; i >= 0; --i) {
		(ans *= R[L[i] + 1]) %= MOD;
	}
	cout << ans % MOD << endl;

	return 0;
}
