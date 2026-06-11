#include <bits/stdc++.h>
using namespace std;
int INF = 10000000;
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> E(N * 3);
  for (int i = 0; i < M; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u * 3].push_back(v * 3 + 1);
    E[u * 3 + 1].push_back(v * 3 + 2);
    E[u * 3 + 2].push_back(v * 3);
  }
  int S, T;
  cin >> S >> T;
  S--;
  T--;
  vector<int> d(N * 3, INF);
  d[S * 3] = 0;
  queue<int> Q;
  Q.push(S * 3);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (auto w : E[v]){
      if (d[w] == INF){
        d[w] = d[v] + 1;
        Q.push(w);
      }
    }
  }
  if (d[T * 3] == INF){
    cout << -1 << endl;
  } else {
    cout << d[T * 3] / 3 << endl;
  }
}