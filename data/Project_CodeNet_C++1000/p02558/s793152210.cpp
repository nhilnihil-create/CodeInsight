#include <bits/stdc++.h>
using namespace std;

const int nax = 2e5+5;
vector<int> p(nax);
vector<int> r(nax);

int par(int a) {
	return p[a] == a ? a : p[a] = par(p[a]);
}

bool IsSameSet(int a, int b) {
	return par(a) == par(b);
}

void merge(int a, int b) {
	if(!IsSameSet(a, b)) {
		int x = par(a), y = par(b);
		if(r[x] > r[y]) {
			p[y] = x;
		}
		else {
			p[x] = y;
			if(r[x] == r[y]) r[y]++;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, q, t, u, v;
	cin >> n >> q;
	for(int i = 0; i < n; i++) p[i] = i, r[i] = 0;
	while(q--) {
		cin >> t >> u >> v;
		if(!t) merge(u, v);
		else cout << IsSameSet(u, v) << endl;
	}
	return 0;
}
