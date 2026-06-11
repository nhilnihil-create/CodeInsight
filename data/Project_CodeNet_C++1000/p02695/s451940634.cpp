#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, q;
vector<int> a, b, c, d;

void dfs(vector<int>& A, int& ans) {
	int tmp = 0;
	if (A.size() == n + 1) {
		for (int i = 0; i < q; i++) {
			if (A[b.at(i)] - A[a.at(i)] == c.at(i)) tmp += d.at(i);			
		}
		ans = max(ans, tmp);
		return;
	}
	for (int i = A.back(); i <= m; i++) {
		A.push_back(i);
		dfs(A, ans);
		A.pop_back();
	}
	return;
}

int main() {

	cin >> n >> m >> q;
	a.resize(q);
	b.resize(q);
	c.resize(q);
	d.resize(q);
	for (int i = 0; i < q; i++) {	
		cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
	}
	int ans = 0;
	vector<int> A = { 1 };
	dfs(A, ans);
	cout << ans << endl;
	return 0;
}