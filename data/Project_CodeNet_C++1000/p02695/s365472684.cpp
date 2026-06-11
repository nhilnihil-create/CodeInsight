// N, M, Q
// Q times ai, bi, ci, di
// A (vector)
// A -> N (size)
// Ai <= M
// A[b[i]] - A[a[i]] == c[i] -> Sum d[i];
// Find Max score!

#include <bits/stdc++.h>
using namespace std;

int n, m, q;
vector<int> a, b, c, d, A;
int ans = 0;

int check() {
	int res = 0;
	for (int i = 0; i < q; i++) {
		if(A[b[i] - 1] - A[a[i] - 1] == c[i]) {
			res += d[i];
		}
	}
	return res;
}

void makeSequence(int i, int cur) {
	if(i >= n) {
		// find our score!
		ans = max(ans, check());
		return;
	}

	for (int j = cur; j <= m; j++) {
		A.push_back(j);
		makeSequence(i + 1, j);
		A.pop_back();
	}
}

int main() {
	cin >> n >> m >> q;
	a = b = c = d = vector<int>(q);

	for (int i = 0; i < q; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	makeSequence(0, 1);

	cout << ans << "\n";
}