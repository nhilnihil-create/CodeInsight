#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using VL = vector<LL>;

#define REP(i, n) for (LL i = 0, i##_size = n; i < i##_size; ++i)
#define RREP(i, n) for (LL i = LL(n) - 1; i >= 0; --i)

template <class T> void chmin(T& a, T b) { if (b < a) { a = b; } }
template <class T> void chmax(T& a, T b) { if (b > a) { a = b; } }

#define IN_LL(var) LL var; cin >> var;
#define IN_VL(var, n) VL var(n); REP(i, n) { cin >> var[i]; };

#define OUT(var) cout << (var) << '\n';

void myMain();
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	myMain();
	return 0;
}

void myMain() {
	IN_LL(N);
	IN_VL(A, N + 1);

	if (N == 0) {
		if (A[0] == 1) {
			cout << 1 << endl;
		}
		else {
			cout << -1 << endl;
		}
		return;
	}

	VL minCount(N + 1);
	VL maxCount(N + 1);

	minCount[N] = A[N];
	maxCount[N] = A[N];
	RREP(i, N) {
		minCount[i] = (minCount[i + 1] + 1) / 2 + A[i];
		maxCount[i] = maxCount[i + 1] + A[i];
	}

	LL ans = 1;
	maxCount[0] = 1;
	REP(i, N) {
		LL m = (maxCount[i] - A[i]) * 2;
		if (m < minCount[i + 1]) {
			OUT(-1);
			return;
		}

		chmin(maxCount[i + 1], m);
		ans += maxCount[i + 1];
	}

	OUT(ans);
}