#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 19], cnt[1 << 19], cl[1 << 19], ans[1 << 19], r[1 << 19];
vector<long long> E;

void init() {
	for (int i = 1; i <= N; i++) r[cnt[i]]++;
	for (int i = N; i >= 1; i--) r[i] += r[i + 1];

	for (int i = N; i >= 1; i--) {
		for (int j = r[i]; j >= 1; j--) E.push_back(j);
	}
}

long long solve(int pos) {
	vector<int> cntv(N + 1, 1);
	vector<int> cntk(N + 1, 0);

	int umaru = 0;
	for (int i = 0; i < E.size(); i++) {
		if (cntk[cntv[E[i]]] < pos) {
			cntk[cntv[E[i]]]++;
			if (cntk[cntv[E[i]]] == pos) umaru = max(umaru, cntv[E[i]]);
			cntv[E[i]] += 1;
		}
		else {
			cntv[E[i]] = umaru + 1;
			cntk[cntv[E[i]]]++;
			if (cntk[cntv[E[i]]] == pos) umaru = max(umaru, cntv[E[i]]);
			cntv[E[i]] += 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (cntk[i] < pos) return i - 1;
	}
	return N;
}

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) { scanf("%lld", &A[i]); cnt[A[i]]++; }
	init();

	int ret = 0; cl[0] = N;
	for (int i = 1; (i * i) <= N; i++) {
		long long sum = 0;
		for (int j = 1; j <= N; j++) { sum += min(cnt[j], 1LL * i); }
		cl[i] = sum / i; ret++;
		for (int k = cl[i] + 1; k <= cl[i - 1]; k++) ans[k] = i - 1;
	}

	for (int i = 1; i <= cl[ret]; i++) {
		ans[i] = solve(i);
	}
	for (int i = 1; i <= N; i++) printf("%lld\n", ans[i]);
	return 0;
}