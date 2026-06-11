#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n;
  cin >> n;
  vector<vector<pair<int, int> > > data(n);
  for (int i = 0; i < n; i++) {
    int sz;
    cin >> sz;
    data[i].resize(sz);
    for (int j = 0; j < sz; j++) {
      cin >> data[i][j].first >> data[i][j].second;
      data[i][j].first--;
    }
  }
  int mask = (1 << n) - 1, ans = 0;
  while (mask > 0) {
    int ppl = mask, i = n - 1;
    bool poss = true;
    while (ppl) {
      if (ppl & 1) {
        for (pair<int, int> p : data[i]) {
          if (p.second ^ (bool)(1 << (n - 1 - p.first)&mask))
            poss = false;
        }
      }
      ppl /= 2;
      i--;
    }
    if (poss) {
      ans = max(ans, __builtin_popcount(mask));
    }
    mask--;
  }
  cout << ans;
  return 0;
}