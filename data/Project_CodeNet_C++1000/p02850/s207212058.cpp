#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)

#define ALL(v) v.begin(), v.end()

int main() {
  std::cout << std::fixed << std::setprecision(20);

  int64_t N;
  cin >> N;
  
  vector<vector<pair<int64_t,int64_t>>> G(N,vector<pair<int64_t,int64_t>>());


  REP(i,N-1){
    int64_t a, b;
    cin >> a >> b;
    G[a-1].emplace_back(b-1,i);
    G[b-1].emplace_back(a-1,i);
  }

  vector<int64_t> color(N-1,-1);
  vector<int64_t> dist(N,-1);
  queue<int64_t> que;

  que.push(0);
  dist[0] = 0;

  while(!que.empty()){
    int64_t v = que.front();
    que.pop();

    int64_t c = dist[v];
    int64_t i = 1;
    for(pair<int64_t,int64_t> nv: G[v]){
      if(dist[nv.first] != -1) continue;
      if(c == i) i++;
      dist[nv.first] = i;
      color[nv.second] = i;
      i++;
      que.push(nv.first); 
    }
  }

  int64_t ans = -1;
  REP(i,N-1){
    ans = max(ans,color[i]);
  }
  cout << ans << endl;
  REP(i, N-1) cout << color[i] << endl;
  
}