#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl

int main() {
  // 入力
  int N, D;
  cin >> N >> D;

  vector<vector<int>> vvi(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < D; j++) {
      int x;
      cin >> x;
      vvi.at(i).push_back(x);
    }
  }
  
  // 計算
  int count = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      if (i >= j) continue;
      
      auto p1 = vvi.at(i);
      auto p2 = vvi.at(j);
      
      double sum = 0.0;
      for (int k = 0; k < D; k++) {
        sum += pow(p1.at(k) - p2.at(k), 2);
      }
      double dis = sqrt(sum);
      if (floor(dis) == dis) {
        count++;
      }
    }
  }
  
  // 出力
  println(count);
}