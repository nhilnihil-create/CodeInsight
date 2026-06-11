#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int mod = 1e9 + 7;

int main(){ 
  int n;
  cin >> n;
  vector<vector<P>> g(n);
  rep(i,n - 1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].emplace_back(make_pair(b, i));
    g[b].emplace_back(make_pair(a, i));
  }
  vector<int> color(n - 1, 0);

  auto dfs = [&](auto& f, int u, int p, int pc)->void{
    int c = 1;
    for (auto e : g[u]) {
      int v = e.first, id = e.second;
      if (p == v) continue;
      if (c == pc) c++;
      color[id] = c;
      f(f, v, u, c);
      c++;
    }
  };
  dfs(dfs, 0, -1, 0);
  cout << *max_element(color.begin(), color.end()) << endl;
  for (auto e : color) cout << e << endl;
  return 0; 
} 
