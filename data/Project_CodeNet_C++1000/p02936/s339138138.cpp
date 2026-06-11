#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> a(200000);
vector<long long> ans(200000);

void dfs(int n, int p);

int main()
{
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		int p, q;
		cin >> p >> q;
		p--;
		q--;

		a[p].emplace_back(q);
		a[q].emplace_back(p);
	}
	for (int i = 0; i < q; i++) {
		int p, x;
		cin >> p >> x;
		ans[p - 1] += x;
	}

	dfs(0, 0);

	for (int i = 0; i < n; i++) {
		cout << ans[i] << (n == i + 1 ? "\n" : " ");
	}

	return 0;
}

void dfs(int n, int p)
{
	for (auto & i : a[n]) {
		if (p == i) continue;

		ans[i] += ans[n];
		dfs(i, n);
	}
}