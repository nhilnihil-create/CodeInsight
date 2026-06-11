#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h, w;
  cin >> h >> w;

  // 障害物の情報
  vector<vector<int>> xs(h);
  vector<vector<int>> ys(w);

  // 番兵として、h,wの0番目とn番目に障害物を入れる
  rep(i, w) {
    ys[i].push_back(0);
    ys[i].push_back(h+1);
  }
  rep(i, h) {
    xs[i].push_back(0);
    xs[i].push_back(w+1);
  }
  rep(i, h) {
    rep(j, w) {
      int x = j+1;
      int y = i+1;
      char c;
      cin >> c;
      // 障害物がある場合にxs,ysに障害物の情報を入れる
      if(c == '#') {
        xs[i].push_back(x);
        ys[j].push_back(y);
      }
    }
  }

  // ソートする
  rep(i, w) {
    sort(ys[i].begin(), ys[i].end());
  }
  rep(i, h) {
    sort(xs[i].begin(), xs[i].end());
  }

  // 明かりの数を調べる
  int max_cnt = 0;
  rep(i, h) {
    rep(j, w) {
      int x = j+1;
      int y = i+1;

      if(binary_search(xs[i].begin(), xs[i].end(), x) || binary_search(ys[j].begin(), ys[j].end(), y)) {
        // 障害物の上なのでskip
        continue;
      }

      auto l_at = lower_bound(xs[i].begin(), xs[i].end(), x);
      int xrange = *l_at - *prev(l_at) - 1;
      auto u_at = lower_bound(ys[j].begin(), ys[j].end(), y);
      int yrange = *u_at - *prev(u_at) - 1;

      // printf("(%d, %d): %d - %d\n", x, y, *next(l_at), *l_at);
      // printf("(%d, %d): xrange -> %d, yrange -> %d\n", x, y, xrange, yrange);

      int cnt = xrange + yrange - 1;
      max_cnt = max(cnt, max_cnt);
    }
  }

  cout << max_cnt << endl;
  return 0;
}