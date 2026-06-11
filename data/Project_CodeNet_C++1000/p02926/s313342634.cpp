/**
 * 降参。
 * 解説の方法を試す
 */
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <cmath>

using namespace std;

struct point {
  int x;
  int y;
};

int main() {
  int n;
  cin >> n;
  vector<point> points(n);

  for (int i = 0; i < n; i++) {
    int x,y;
    cin >> x >> y;
    points[i] = {x,y};
  }

  // 偏角ソート
  // 浮動小数点の精度について考慮必要？
  sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
      return atan2l(a.y, a.x) > atan2l(b.y, b.x); }); // atan2は、座標から偏角を計算する関数。(atanはtanから計算)。lは精度(long double)

  long long int result = 0ll;

  // iを端点として、結果計算
  // O(N**2)かかるけど、Nが小さいので問題なし
  // Nが大きい場合は尺取法とか使うといいらしいが面倒くさそう
  for (int i = 0; i < n; i++) {
    long long int x = 0;
    long long int y = 0;

    for (int j = 0; j < n; j++) {
      int k = (i+j) % n;
      int k_x = points[k].x;
      int k_y = points[k].y;

      x += k_x;
      y += k_y;

      result = max(result, x*x+y*y);
    }
  }

  cout << fixed << setprecision(15) << sqrtl(result) << endl;
}
