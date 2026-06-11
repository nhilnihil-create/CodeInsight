#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main(){
  int n,d;
  cin >> n >> d;
  std::vector<std::vector<int>> x(n,std::vector<int>(d));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d; j++) {
      cin >> x[i][j];
    }
  }
  int ans = 0;
  // ----組み合わせ----
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      // --------------
      int norm = 0;
      for (int k = 0; k < d; k++) {
        // D次元空間上の値をnormに格納していく
        int diff = abs(x[i][k] - x[j][k]);
        norm += diff * diff;
      }
      // normが整数か判定する
      bool flag = false;
      for (int k = 0; k <= norm; k++) {
        if (k * k == norm) {
          flag = true;
        }
      }
      if (flag) ans++;
    }
  }
  cout << ans << endl;
}
