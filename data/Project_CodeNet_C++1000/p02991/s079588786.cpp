#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M; cin >> N >> M;
  vector<vector<vector<pair<int, int> > > > E(N, vector<vector<pair<int, int> > >(3, vector<pair<int, int> >()));
  REP(i, M){
    int u, v; cin >> u >> v; u--; v--;
    E[u][0].push_back({v, 1});
    E[u][1].push_back({v, 2});
    E[u][2].push_back({v, 0});
  }
  int S, T; cin >> S >> T; S--; T--;
  vector<vector<int> > dist(N, vector<int>(3, -1));
  queue<pair<int, int> > q;
  q.push({S, 0});
  dist[S][0] = 0;
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(auto nxt : E[cur.first][cur.second]){
      if(dist[nxt.first][nxt.second] != -1) continue;
      dist[nxt.first][nxt.second] = dist[cur.first][cur.second] + 1;
      q.push(nxt);
    }
  }
  cout << (dist[T][0] == -1 ? -1 : dist[T][0]/3) << endl;
}