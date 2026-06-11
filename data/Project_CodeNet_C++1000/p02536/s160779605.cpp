#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> E(N);
  for (int i = 0; i < M; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<bool> used(N, false);
  int ans = 0;
  for (int i = 0; i < N; i++){
    if (!used[i]){
      used[i] = true;
      ans++;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (!used[w]){
            used[w] = true;
            Q.push(w);
          }
        }
      }
    }
  }
  cout << ans - 1 << endl;
}
