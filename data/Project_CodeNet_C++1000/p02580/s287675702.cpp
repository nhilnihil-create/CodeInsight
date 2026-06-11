#include <bits/stdc++.h>
#define rep(i, ns, ne) for (int i = ns; i < ne; ++i)
using namespace std;

// pair(y,x)と同じ
struct P {
  int y;
  int x;
  P(int _y, int _x) : y(_y), x(_x) {}
  // LHS = left-hand side RHS = right-hand side
  bool operator<(const P &rhs) const {
    // y の値を優先してソートするなら
    return y != rhs.y ? y < rhs.y : x < rhs.x;
  }
};

int main() {

  // 入力
  int H, W, M;
  cin >> H >> W >> M;

  vector<int> hs(H), ws(W);
  set<P> sp;

  rep(i, 0, M) {
    int y, x;
    cin >> y >> x;
    --y, --x;
    hs[y]++, ws[x]++;
    sp.emplace(y, x); //物がある座標
  }

  // 縦横の最大値
  int maxH = *max_element(hs.begin(), hs.end());
  int maxW = *max_element(ws.begin(), ws.end());

  // 縦最大だけのy座標
  vector<int> maxhs;
  rep(i, 0, H) {
    if (maxH == hs[i]) {
      maxhs.emplace_back(i);
    }
  }

  // 横最大だけのx座標
  vector<int> maxws;
  rep(i, 0, W) {
    if (maxW == ws[i]) {
      maxws.emplace_back(i);
    }
  }

// 縦最大と横最大の交点を確認
  int ans = maxH + maxW;
  for (auto yy : maxhs) {
    for (auto xx : maxws) {

      // 交点に物があるか確認
      if (sp.count(P(yy, xx))) {
        continue;
      }
      //交点に物が無い場所があったら終了
      cout << ans << endl;
      return 0;
    }
  }

  //交点に物が無い場所が無い場合は交差する1点を引く
  ans--;
  cout << ans << endl;
  getchar();
}
