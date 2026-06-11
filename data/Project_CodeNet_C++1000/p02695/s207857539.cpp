#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> a, b, c, d;
int ans = 0;

void dfs(int val, int n, int m, int q, vector<int> A) {
	if (A.size() == n) {
		int tmp = 0;
		for (int i = 0; i < q; i++) {
			if (A[b[i]] - A[a[i]] == c[i]) tmp += d[i];
		}
		ans = max(ans, tmp);		
	}
	else {
		A.push_back(val);
		for (int i = 1; i <= m; i++) {
			if (i < val) continue;
			dfs(i, n, m, q, A);
		}
	}
	return;
}


int main() {

	int n, m, q; cin >> n >> m >> q;
	a.resize(q);
	b.resize(q);
	c.resize(q);
	d.resize(q);
	for (int i = 0; i < q; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		--a[i];
		--b[i];
	}
	vector<int> A;
	int val = 1;
	dfs(val, n, m, q, A);
	cout << ans << endl;
	return 0;
}