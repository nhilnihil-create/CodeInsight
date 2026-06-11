#include <bits/stdc++.h>
#define M_PI           3.14159265358979323846  /* pi */
using namespace std;
using  ll = long long;

struct Unionfind {
	vector<int>p;
	Unionfind(int n) {
		p.resize(n, -1);
	}

	int find(int x) {
		if (p[x-1] == -1)return x;
		else return p[x-1] = find(p[x-1]);
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)return;
		p[x-1] = y;
	
	
	}
};


int main() {
	int n, m, x, y;
	cin >> n >> m;
	Unionfind uf(n);

	
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		uf.unite(x, y);
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (uf.p.at(i) == -1)count++;
	}
	cout << count - 1 << endl;
}



