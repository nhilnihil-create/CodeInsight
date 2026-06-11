#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'


class UnionFind {
public:
  vector<int> parent, size;
  
  UnionFind(int n) {
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    size.resize(n, 1);
  }  
  
  int Find(int x) {
    return x == parent[x] ? x : parent[x] = Find(parent[x]);
  }
  bool Merge(int x, int y) {
    int px = Find(x), py = Find(y);
    if (px == py) return false;
    if (size[px] < size[py]) swap(px, py);
    parent[py] = px;
    size[px] += size[py];
    return true;
  }
};

 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll n,m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  UnionFind uf(n);
  int ans = n-1;
  for (int i = 0; i < m; ++i) {
    int u,v;
    cin >> u >> v;
    --u, --v;
    if (uf.Merge(u,v)) {
      --ans;
    }
  }
  cout << ans << endl;


}
