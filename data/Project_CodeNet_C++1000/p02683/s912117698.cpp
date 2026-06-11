#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, x, S = 0, min = 10e7;
  bool c = true;
  cin >> n >> m >> x;
  vector<vector<int>> v(n, vector<int>(m + 1));
  for(int i = 0;i < n;i++) {
    for(int j = 0;j <= m;j++) {
      cin >> v[i][j];
    }
  }
  for(int i = 0;i < (1 << 12);i++) {
    bitset<12> b(i);
    vector<int> s(m);
    c = true;
    S = 0;
    for(int j = 0;j < n;j++) {
      if(b.test(j)) {
        S += v[j][0];
        for(int k = 0;k < m;k++) {
          s[k] += v[j][k + 1];
        }
      }
    }
    for(int j = 0;j < m;j++) {
      if(s[j] < x) {
        c = false;
        break;
      }
    }
    if(c && S < min) min = S; 
  }
  cout << (min < 10e7 ? min : -1) << endl;
}