#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct UF {
  vector<int> par;
  UF(int N) : par(N) {
    for(int i = 0; i < N; i++) par[i] = i;
  }
  int root(int x) {
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  void unite(int x, int y) {
    int rx = root(x); int ry = root(y);
    if(rx == ry) return;
    par[rx] = ry;
  }
  bool same(int x, int y) {
    int rx = root(x); int ry = root(y);
    return rx == ry;
  }
};
  
int main() {
  int N, M; cin >> N >> M;
  UF tree(N);
  for(int i = 0; i < M; i++) {
    int x, y; cin >> x >> y;
    x--; y--;
    tree.unite(x, y);
  }
  vector<int> parents(0);
  map<int, int> roots;
  for(int i = 0; i < N; i++) {
    int ri = tree.root(i);
    if(roots.count(ri)) roots.at(ri)++;
    else {
      roots[ri] = 1;
      parents.push_back(ri);
    }
      //cout << ri << " r" << i << endl;
  }
  int cnt = 0;
  for(int i = 0; i < parents.size(); i++) {
    cnt = max(cnt, roots.at(parents.at(i)));
  }
  cout << cnt << endl;
}