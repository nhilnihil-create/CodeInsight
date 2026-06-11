#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> g[100005];
int main() {
  int n,m;
  cin >> n >> m;
  rep(i,m){
    int u,v;
    cin >> u >> v;
    --u; --v;
    g[u].emplace_back(v);
  }
  int s,t;
  cin >> s >> t;
  --s; --t;

  vector<vector<int>> dist(n,vector<int>(3,-3));
  queue<P> q;
  auto push = [&](int v, int d){
    if(0<=dist[v][d%3] && dist[v][d%3]<=d) return;
    dist[v][d%3] = d;
    q.emplace(v,d);
  };
  push(s,0);
  while(!q.empty()){
    P p = q.front(); q.pop();
    for(int v:g[p.first]){
      push(v,p.second+1);
    }
  }
  cout << dist[t][0]/3 << endl;
}
