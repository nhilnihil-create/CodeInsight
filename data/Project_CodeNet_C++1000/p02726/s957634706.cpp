#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x, y;
	cin >> n >> x >> y;
	vector<int> cnt(n);
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			cnt[min({j - i, abs(x - i) + abs(j - y) + 1, abs(y - i) + abs(j - x) + 1})]++;
	for (int i = 1; i < n; ++i)
		cout << cnt[i] << '\n';
	return 0;
}