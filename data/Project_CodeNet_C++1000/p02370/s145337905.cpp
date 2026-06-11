#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  // トポロジカルソート
  int V, E; cin >> V >> E;
  vector<vector<int> > edge(V, vector<int>());
  vector<int> h(V, 0);
  REP(i, E){
    int x, y; cin >> x >> y;
    edge[x].push_back(y);
    h[y]++;
  }
  queue<int> q;
  REP(i, V){
    if(h[i] == 0) q.push(i);
  }
  vector<int> ans;
  while(!q.empty()){
    int i = q.front(); q.pop();
    ans.push_back(i);
    for(auto j : edge[i]){
      h[j]--;
      if(h[j] == 0) q.push(j);
    }
  }
  for(auto &i : ans) cout << i << endl;
}
