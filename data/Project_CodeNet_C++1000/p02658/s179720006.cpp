#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N;
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		if (A[i] == 0) {
			cout << 0 << endl;
			return 0;
		}
	}

	ll ans = 1;
	for (int i = 0; i < N; ++i) {
		if (A[i] <= 1000000000000000000 / ans) {
			ans *= A[i];
		}
		else {
			ans = -1;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
