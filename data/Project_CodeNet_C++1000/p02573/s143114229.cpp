#include <iostream>
#include <bitset>
#include <math.h>
#include <algorithm>
#include <vector>;
using namespace std;

vector<int> r;

int root(int x) {
	if (r[x] < 0) return x;
	return r[x] = root(r[x]);
}

bool unite(int x, int y) {
	x = root(x);
	y = root(y);
	if (x == y) return false;

	if (r[x] < r[y]) swap(x, y);
	r[y] += r[x];
	r[x] = y;
	return true;
}

int main() {
	
	int n, m;
	cin >> n >> m;

	r = vector<int>(n,-1);

	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		unite(a, b);
	}

	int ans = -1;
	for (int i = 0;i < n;i++) {
		ans = max(ans, -r[root(i)]);
	}

	cout << ans << endl;

	return 0;
}