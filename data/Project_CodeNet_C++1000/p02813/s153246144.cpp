#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, cntP = -1, cntQ = -1, cntT = 1;
	cin >> n;
	vector<int> P(n), Q(n), seq(n);

	for (int i = 0; i < n; i++)
		cin >> P[i];
	for (int i = 0; i < n; i++)
		cin >> Q[i];

	seq = P;
	sort(seq.begin(), seq.end());
	if (P == seq)
		cntP = 0;
	if (Q == seq)
		cntQ = 0;

	while (next_permutation(seq.begin(), seq.end())) {
		if (P == seq)
			cntP = cntT;
		if (Q == seq)
			cntQ = cntT;
		cntT++;
	}

	cout << abs(cntP - cntQ) << endl;
}
