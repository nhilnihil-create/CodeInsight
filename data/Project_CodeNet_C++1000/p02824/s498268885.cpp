#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	Int N, M, V, P;
	cin >> N >> M >> V >> P;
	vector<Int> A(N);
	for (int i = 0; i < N; ++i) { cin >> A[i]; }

	sort(A.rbegin(), A.rend());
	auto check = [&](int m) -> bool {
		Int cnt = 0;
		for (int i = 0; i < N; ++i) {
			if (A[i] > A[m] + M) { ++cnt; }
		}
		if (cnt >= P) { return false; }

		Int sum = M;
		cnt = 1;
		for (int i = 0; i < N; ++i) {
			if (i == m) { continue; }
			if (cnt++ < P) { sum += M; }
			else { sum += min(M, A[m] + M - A[i]); }
		}
		return sum >= M * V;
	};

	int l = 0, r = N;
	while (r - l > 1) {
		int m = (r + l) / 2;
		(check(m) ? l : r) = m;
	}
	cout << l + 1 << "\n";

	return 0;
}
