#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int64_t sum = 0; //葉の合計
  for (int i = 0; i < n + 1; i++) {
    cin >> a.at(i);
    sum += a.at(i);
  }
  if (n == 0 && a.at(0) == 1)
    cout << 1 << endl;
  
  else if (a.at(0) >= 1) {
    cout << -1 << endl;
  }
  
  
  else {
    int64_t point = 1; //深さ0の頂点の数
    int64_t count = 1; //頂点の合計
    for (int i = 0; i < n; i++) {
      sum -= a.at(i);
      int64_t nleaf = point - a.at(i); //深さiの頂点から葉を引いた数
      
      if (nleaf * 2 < a.at(i + 1)) {
        cout << -1 << endl;
        break;
      }
      
      else {
        count += min(nleaf * 2, sum);
        point = min(nleaf * 2, sum);
      }
    
      if (i == n - 1)
        cout << count << endl;
    }
  }
}