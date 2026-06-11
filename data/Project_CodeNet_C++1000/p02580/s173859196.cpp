#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

const int N = 300000, M = 300000, K = 300000;

int xx[K], yy[K];
int kkx[1 + N], kky[1 + M];
map<pair<int, int>, bool> mp;
int qux[N], quy[N];

int main() {
	int n, m, k; cin >> n >> m >> k;
	for (int h = 0; h < k; h++)
		cin >> xx[h] >> yy[h];
	for (int h = 0; h < k; h++) {
		kkx[xx[h]]++, kky[yy[h]]++;
		mp[make_pair(xx[h], yy[h])] = true;
	}
	int kx = 0;
	for (int x = 1; x <= n; x++)
		kx = max(kx, kkx[x]);
	int ky = 0;
	for (int y = 1; y <= m; y++)
		ky = max(ky, kky[y]);
	int cntx = 0;
	for (int x = 1; x <= n; x++)
		if (kkx[x] == kx)
			qux[cntx++] = x;
	int cnty = 0;
	for (int y = 1; y <= m; y++)
		if (kky[y] == ky)
			quy[cnty++] = y;
	for (int hx = 0; hx < cntx; hx++)
		for (int hy = 0; hy < cnty; hy++)
			if (!mp[make_pair(qux[hx], quy[hy])]) {
				cout << kx + ky << '\n';
				return 0;
			}
	cout << kx + ky - 1 << '\n';
	return 0;
}
