#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repab(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define pb push_back
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
#define endl "\n"

typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int INF = 1001001001;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};

//--//--//--//--//--//--//--//--//--//--//--//

// UnionFind
struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};

int main(){
	int n, m;
	cin >> n >> m;
	UnionFind uf(n);
	rep(i, m){
		int a, b;
		cin >> a >> b;
		--a; --b;
		uf.unite(a, b);
	}

	int ans = 0;
	rep(i, n){
		ans = max(ans, uf.size(i));
	}
	cout << ans << endl;
}