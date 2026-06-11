#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> a(n);
  for (int i = 0; i < n; i++) {
    int an;
    cin >> an;
    vector<pair<int, int>> xy(an);
    for (int j = 0; j < an; j++) {
      cin >> xy.at(j).first >> xy.at(j).second;
      xy.at(j).first--;
    }
    a.at(i) = xy;
  }
  int ans = 0;
  for (int bit = 0; bit < (1 << n); bit++) {
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (bit & (1 << i)) {
        for (int j = 0; j < a.at(i).size(); j++) {
          int x = a.at(i).at(j).first;
          int y = a.at(i).at(j).second;
          if (y == 1 && !(bit & (1 << x))) {
            flag = false;
            break;
          }
          if (y == 0 && bit & (1 << x)) {
            flag = false;
            break;
          }
        }
      }
    }
    if (flag) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (bit & (1 << i)) {
          cnt++;
        }
      }
      ans = max(ans, cnt);
    }
  }
  cout << ans << endl;
  return 0;
}