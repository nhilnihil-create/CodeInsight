#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, K;
  cin >> N >> K;
  if (K > (N - 1) * (N - 2) / 2){
    cout << -1 << endl;
  } else {
    vector<pair<int, int>> E;
    for (int i = 1; i < N; i++){
      E.push_back(make_pair(1, i + 1));
    }
    K = (N - 1) * (N - 2) / 2 - K;
    for (int i = 2; i <= N; i++){
      for (int j = i + 1; j <= N; j++){
        if (K > 0){
          E.push_back(make_pair(i, j));
          K--;
        }
      }
    }
    int M = E.size();
    cout << M << endl;
    for (int i = 0; i < M; i++){
      cout << E[i].first << ' ' << E[i].second << endl;
    }
  }
}