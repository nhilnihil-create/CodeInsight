#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;

int par[maxN], siz[maxN];

void init() {
	for (int i = 0; i < maxN; ++i) {
    	par[i] = i, siz[i] = 1; 
    }
}

int find(int x) {
	return par[x] == x ? x : par[x] = find(par[x]); 
}

bool same(int x, int y) {
	return find(x) == find(y);  
}

void unify(int x, int y) {
	x = find(x), y = find(y);
  	if (x == y) return;
  	if (siz[x] > siz[y]) {
    	siz[x] += siz[y];
      	par[y] = x;
    }
  	else {
    	siz[y] += siz[x];
      	par[x] = y;
    }
}

int main() {
	int n, q;
  	cin >> n >> q;
  	init();
  	for (int i = 0; i < q; ++i) {
    	int type, u, v;
      	cin >> type >> u >> v;
      	if (type) {
         	cout << same(u, v) << '\n';          
        }
      	else {
 			unify(u, v);
        }
    }
  	return 0;
}