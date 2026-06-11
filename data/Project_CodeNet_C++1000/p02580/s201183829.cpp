#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
#define rep(i, ne) for (int i = 0; i < ne; ++i)

set<P> st; // first=y second=x
int H, W, M;
void input() {
  cin >> H >> W >> M;
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    st.emplace(a, b);
  }
}

void solve() {
  map<int, int> mapY, mapX;
  int maxY = 0, maxX = 0;
  for (auto p : st) {
    maxY = max(maxY, ++mapY[p.first]);
    maxX = max(maxX, ++mapX[p.second]);
  }

  vector<int> vY;
  for (auto e : mapY) {
    if (maxY == e.second)
      vY.emplace_back(e.first);
  }
  vector<int> vX;
  for (auto e : mapX) {
    if (maxX == e.second)
      vX.emplace_back(e.first);
  }

  int ans = maxY + maxX;
  for (auto y : vY) {
    for (auto x : vX) {
      if (st.find({y, x}) == st.end()) {
        cout << ans << endl;
        return;
      }
    }
  }
  cout << ans - 1 << endl;
}

int main() {
  input();
  solve();
  getchar();
  return 0;
}

// 写経
// 回答例(C++, kort0n氏より引用)
// https://atcoder.jp/contests/abc176/submissions/16180005
// https://atcoder.jp/contests/abc176/editorial/66