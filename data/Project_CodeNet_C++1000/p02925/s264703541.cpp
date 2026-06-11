#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i, n) for(int (i)=0; (i)< (n); ++i)
#define REPR(i, n) for(int (i)=(n); (i)>=0; --i)
#define FOR(i, n, m) for(int (i)=(n); (i)<(m); ++i)
constexpr int INF = 1e9;
//constexpr ll INF = 1LL << 62;
constexpr int mod = 1e9+7;

vector<vector<int>> g;
vector<int> in, out, dist;
vector<bool> homon;
bool ans = true;
void bfs(int V){
  queue<int> que;
  REP(i, V){
    if(in[i] == 0){
       que.push(i);
       homon[i]=true;
    }
  }
  if(que.empty()) ans = false;
  while(!que.empty()){
    int v = que.front(); que.pop();
    for(auto nv : g[v]){
      dist[nv] = max(dist[nv], dist[v]+1);
      in[nv]--;
      if(in[nv] == 0){
         que.push(nv);
         homon[nv] = true;
      }
    }
  }
  REP(i, V){
    if(!homon[i]) ans = false;
  }
}
int main(){
  int N;
  cin >> N;
  int V = 0;
  vector<vector<int>> id(N, vector<int>(N));
  REP(i, N){
    FOR(j, i+1, N){
      id[i][j] = V;
      V++;
    }
  }
  g.resize(V);
  vector<vector<int>> A(N, vector<int>(N-1));
  REP(i, N){
    REP(j, N-1){
      cin >> A[i][j];
      A[i][j]--;
    }
  }
  in.resize(V, 0), out.resize(V, 0);
  dist.resize(V, 0), homon.resize(V, false);
  REP(i, N){
    REP(j, N-2){
      int a = A[i][j], b = A[i][j+1];
      int s = i, t = i;
      if(a > s) swap(a, s);
      if(b > t) swap(b, t);
      s = id[a][s];
      t = id[b][t];
      g[s].push_back(t);
      in[t]++, out[s]++;
    }
  }
  bfs(V);
  int cnt = 0;
  REP(i, V){
    cnt = max(cnt, dist[i]);
  }
  if(ans){
    cout << cnt+1 << endl;
  }
  else{
    cout << -1 << endl;
  }
  return 0;
}
