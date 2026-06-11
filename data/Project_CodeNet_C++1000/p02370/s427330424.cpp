#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int v, e;
  cin >> v >> e;
  vector<int> g[v];
  vector<int> h(v);
  rep(i,e){
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    h[b]++;
  }
  queue<int> que;
  rep(i,v) if(h[i] == 0) que.push(i);
  vector<int> ans;
  while(!que.empty()) {
    int p = que.front(); que.pop();
    ans.push_back(p);
    for(auto i : g[p]) {
      h[i]--;
      if(h[i] == 0) que.push(i);
    }
  }
  rep(i,v) cout << ans[i] << endl;
  return 0;
}
