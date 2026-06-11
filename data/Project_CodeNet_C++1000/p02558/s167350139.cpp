#pragma GCC optimize("O3", "unroll-loops")
#define fs first
#define sc second
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int maxn = 2e5 + 10;

int ptr[maxn], sz[maxn];

int n, q, inst, u, v;

int find(int x) {
	return (ptr[x] == x) ? x: ptr[x] = find(ptr[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (sz[x] >= sz[y])
		ptr[y] = x, sz[x] += sz[y];
	else
		ptr[x] = y, sz[y] += sz[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		ptr[i] = i;
	while (q--) {
		cin >> inst >> u >> v;
		if (inst)
			cout << (find(u) == find(v)) << '\n';
		else
			merge(u, v);
	}
	return 0;
}
