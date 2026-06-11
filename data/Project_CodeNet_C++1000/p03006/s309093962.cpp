#include <bits/stdc++.h>
using namespace std;
int INF = 1000;
int main(){
  int N;
  cin >> N;
  vector<int> x(N), y(N);
  for (int i = 0; i < N; i++){
    cin >> x[i] >> y[i];
  }
  int ans = INF;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      int p = x[j] - x[i];
      int q = y[j] - y[i];
      vector<vector<int>> E(N);
      for (int k = 0; k < N; k++){
        for (int l = 0; l < N; l++){
          if (x[l] - x[k] == p && y[l] - y[k] == q){
            E[k].push_back(l);
            E[l].push_back(k);
          }
        }
      }
      vector<bool> used(N, false);
      int cnt = 0;
      for (int k = 0; k < N; k++){
        if (!used[k]){
          used[k] = 0;
          queue<int> Q;
          Q.push(k);
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
          cnt++;
        }
      }
      ans = min(ans, cnt);
    }
  }
  cout << ans << endl;
}