#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;

#define FOR(i, N) for (int i = 0; i < N; i++)


vector<ll> binary_gauss_jordan(const vector<ll>& x) {
	vector<ll> y(x);
	int sz = x.size();

	FOR(i, sz) {
		auto imax = max_element(y.begin() + i, y.end()) - y.begin();
		if (y[imax] == 0) break;

		swap(y[i], y[imax]);

		ll msb = 1;

		while ((msb << 1) <= y[i]) msb <<= 1;

		FOR(j, sz)
			if (j != i && y[j] & msb) y[j] ^= y[i];
	}
	return y;
}

int main(void) {
	int N;

	cin >> N;

	vector<ll> A(N);
	ll total = 0;

	FOR(i, N) cin >> A[i];
	FOR(i, N) total ^= A[i];
	FOR(i, N) A[i] &= ~total;

	auto A_std = binary_gauss_jordan(A);

	ll ans = 0;
	FOR(i, A_std.size()) ans = max(ans, ans ^ A_std[i]);

	cout << (2LL * ans + total) << endl;
}