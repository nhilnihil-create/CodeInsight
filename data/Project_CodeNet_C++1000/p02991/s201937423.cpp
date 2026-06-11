#include<bits/stdc++.h>
#define endl '\n';
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 9e18;
constexpr int inf = 1e9;
constexpr double INFD = 1e100;
constexpr ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ---------------------------------------------------------------------------

int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  for(int i=0; i<M; i++){
    int u,v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
  }
  int S,T;
  cin >> S >> T;
  S--;
  T--;
  vector<vector<int>> dist(N,vector<int> (3,-1));
  dist[S][0] = 0;
  queue<P> que;
  que.emplace(S,0);
  while(que.size()){
    P v = que.front();
    que.pop();
    for(int nv: G[v.first]){
      if(dist[nv][(v.second+1)%3] != -1) continue;
      dist[nv][(v.second+1)%3] = dist[v.first][v.second] + 1;
      que.emplace(nv,(v.second+1)%3);
    }
  }
  if(dist[T][0] == -1){
    cout << -1 << endl;
  }else{
    cout << dist[T][0]/3 << endl;
  }
  return 0;
}