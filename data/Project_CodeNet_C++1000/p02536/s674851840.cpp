#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int nm = 1e5;

int r = 0;

//union-find
int par[nm], des[nm];
int root(int v) {
	if (par[v] == v)
		return v;
	return root(par[v]);
}
void unite(int x, int y) {
	int rx = root(x);
	int ry = root(y);
	if (rx == ry)
		return;
	++r;
	if (des[ry] > des[rx])
		swap(rx, ry);
	par[ry] = rx;
	des[rx] += des[ry] + 1;
}
void initUF() {
	for (int i = 0; i < nm; i++)
		par[i] = i;
}

int n, m;

int main() {
	initUF();
	cin >> n >> m;
	for (int i = 0, a, b; i < m; ++i) {
		cin >> a >> b;
		--a;
		--b;
		unite(a, b);
	}
	cout << n - 1 - r << endl;

}
