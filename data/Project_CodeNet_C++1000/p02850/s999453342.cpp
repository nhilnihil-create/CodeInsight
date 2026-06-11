#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<vector<int>> G(n);
  vector<P> vp;
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
    vp.emplace_back(a, b);
  }
  
  int k = 0;
  map<P, int> I;
  vector<int> cs(n, 0);
  
  vector<int> used(n, 0);
  queue<int> que;
  used[0] = 1;
  que.emplace(0);
  while(!que.empty()){
    int v = que.front(); que.pop();
    if (k < (int)G[v].size()) k = G[v].size();
    int cur = 1;
    for(int u : G[v]){
      if (used[u]) continue;
      if (cur == cs[v]) cur++;
      cs[u] = I[make_pair(u, v)] = I[make_pair(v, u)] = cur++;
      used[u] = 1;
      que.emplace(u);
    }
  }
  
  cout << k << endl;
  for(auto p : vp) cout << I[p] << endl;
  return 0;
}