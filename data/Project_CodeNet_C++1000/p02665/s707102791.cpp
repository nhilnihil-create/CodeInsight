#include <bits/stdc++.h>
using namespace std;

#define LL long long

#define FOR(INDEX, START, END) for (LL INDEX = (START); INDEX < (END); ++INDEX)
#define REP(INDEX, COUNT) for (LL INDEX = 0; INDEX < (COUNT); ++INDEX)

LL N;
LL A[100100];
LL minCount[100100];
LL maxCount[100100];

int main()
{
	cin >> N;
	REP(i, N + 1) {
		cin >> A[i];
	}

	if (N == 0) {
		if (A[0] == 1) {
			cout << 1 << endl;
		}
		else {
			cout << -1 << endl;
		}
		return 0;
	}

	minCount[N] = A[N];
	maxCount[N] = A[N];
	for (LL i = N - 1; i >= 0; --i) {
		minCount[i] = (minCount[i + 1] + 1) / 2 + A[i];
		maxCount[i] = maxCount[i + 1] + A[i];
	}

	LL ans = 1;
	maxCount[0] = 1;
	for (LL i = 1; i <= N; ++i) {
		LL m = (maxCount[i - 1] - A[i - 1]) * 2;
		if (m < minCount[i]) {
			cout << -1 << endl;
			return 0;
		}

		maxCount[i] = min(m, maxCount[i]);

		ans += maxCount[i];
	}

	cout << ans << endl;

	return 0;
}
