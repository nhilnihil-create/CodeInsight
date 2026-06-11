#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  long x;
  cin >> n >> m >> x;
  long c[n], a[n][m];
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  
  long min = -1;
  
  // 全探索（2^n 通り. 最大 2^12=4096 通り）
  // 12桁の2進数
  int b = 0b0;
  while (b++ < pow(2, n)) {
    long total_price = 0;
    vector<long> skills(m);
    bool satisfied = true;
    for (int i = 0; i < n; i++) {
      total_price += ((b >> i) & 1)*c[i];
      for (int j = 0; j < m; j++) {
        skills[j] += ((b >> i) & 1)*a[i][j];
      }
    }
    for (int j = 0; j < m; j++) {
      if (skills[j] < x) {
        satisfied = false;
        break;
      }
    }
    if (satisfied && (total_price < min || min == -1)) min = total_price;
  }
  
  cout << min;
  
  return 0;
}