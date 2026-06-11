#include <bits/stdc++.h>

#include <fstream>
using namespace std;

const int INF = 1001001001;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> c(N);
  vector<vector<int>> a(N, vector<int>(M));
  for(int i = 0; i < N; i++){
    cin >> c[i];
    for(int j = 0; j < M; j++){
      cin >> a[i][j];
    }
  }

  int ans = INF;
  for(int i = 1; i < 1 << N; i++){
    int cost = 0;
    vector<int> d(M);
    for(int j = 0; j < N; j++){
      if(i>>j&1){
        cost += c[j];
        for(int k = 0; k < M; k++){
          d[k] += a[j][k];
        }
      }
    }
    bool ok = true;
    for(int j = 0; j < M; j++){
      if(d[j] < X) ok = false;
    }
    if(ok) ans = min(ans, cost);
  }
  if(ans == INF) cout << -1 <<endl;
  else cout << ans <<endl;
}
