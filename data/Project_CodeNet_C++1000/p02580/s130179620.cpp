#include <bits/stdc++.h>

using namespace std;

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int h, w, m;
  cin >> h >> w >> m;
  set<pair<int, int>> st;
  int hmaxval = 0, wmaxval = 0;
  vector<int> hs(h);  // hの爆弾の数
  vector<int> ws(w);  // wの爆弾の数
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    st.insert({x, y});
    hs[x]++;
    chmax(hmaxval, hs[x]);
    ws[y]++;
    chmax(wmaxval, ws[y]);
  }
  vector<int> hmax;
  vector<int> wmax;
  for (int i = 0; i < h; i++) {
    if (hmaxval == hs[i]) {
      hmax.push_back(i);
    }
  }
  for (int i = 0; i < w; i++) {
    if (wmaxval == ws[i]) {
      wmax.push_back(i);
    }
  }
  int ans = hmaxval + wmaxval - 1;
  for (auto x : hmax) {
    for (auto y : wmax) {
      if (st.find({x, y}) == st.end()) {
        cout << ans + 1 << endl;
        return 0;
      }
    }
  }
  cout << ans << endl;
}
