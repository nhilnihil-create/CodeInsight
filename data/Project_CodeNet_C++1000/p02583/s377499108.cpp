#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl
#define yes_or_no(flag) if (flag) { println("Yes"); } else { println("No"); }

int main() {
  // 入力
  int N;
  cin >> N;
  
  vector<int> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L.at(i);
  }
  
  // 計算
  int count = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (i == j || j == k || k == i) continue; // 同じ辺は選べない
        if (i > j || j > k) continue; // 重複カウントを防ぐ
        
        if (L[i] != L[j] && L[j] != L[k] && L[k] != L[i]) {
          vector<int> v = { L[i], L[j], L[k] };
          sort(v.begin(), v.end());
          if ((v.at(0) + v.at(1)) > v.at(2)) {
            count++;
          }
        }
      }
    }
  }
  
  // 出力
  println(count);
}