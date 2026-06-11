#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  long h, w, k;
  cin >> h >> w >> k;

  vector<vector<char>> corg(h, vector<char>(w));

  for (long i = 0; i < h; i++) {
    for (long j = 0; j < w; j++) {
      char tmp;
      cin >> tmp;
      corg.at(i).at(j) = tmp;
    }
  }

  // w * h通り
  long n = h + w;
  long ans = 0;
  for (int bit = 0; bit < (1 << n); ++bit) {
    vector<vector<char>> c(h, vector<char>(w));
    for (long row = 0; row < h; row++) {
      for (long col = 0; col < w; col++) {
        c.at(row).at(col) = corg.at(row).at(col);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {  // 列挙に i が含まれる時
        if (i < h) {
          c.at(i) = vector<char>(w, 'r');
        } else {
          for (long ii = 0; ii < h; ii++) {
            c.at(ii).at(i - h) = 'r';
          }
        }
      }
    }
    // 判定
    long count = 0;
    for (long ii = 0; ii < h; ii++) {
      for (long jj = 0; jj < w; jj++) {
        if (c.at(ii).at(jj) == '#') {
          count++;
        }
      }
    }
    if (count == k) {
      ans++;
    }
  }
  cout << ans << endl;
}
