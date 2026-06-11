#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

const int Nmax = 2e5 + 10;
int f[Nmax], c[Nmax];

int find(int x) {
	if (f[x] != f[f[x]])
		f[x] = find(f[x]);
	return f[x];
}

bool merge(int x, int y) {
	int rx = find(x), ry = find(y);
	if (rx == ry)
		return false;
	f[ry] = rx;
	c[rx] += c[ry];
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		f[i] = i;
		c[i] = 1;
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		merge(x, y);
	}
	int res = 0;
	for (int i = 0; i < n; ++i)
		if (find(i) == i)
			res = max(res, c[i]);
	cout << res << '\n';
	return 0;
}