#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; i++)
#define PI 3.14159265358979323846
//#define v vector<long long>
using namespace std;
using ll = long long;
using ld = long double;

// ----本問について----
// 問題：コッホ曲線
// 問題文URL：https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_C
// 所要時間：
// 学んだこと：
// ------------------

// ----ここから本問のソースコード----

// グローバル変数（入力）
ll n;

void printVert(ld x, ld y) { cout << x << " " << y << endl; }

void koch(ld x0, ld x1, ld y0, ld y1, ll n) {
  if (n == 0) {
    printVert(x0, y0);
  } else {
    // 中間点の座標を計算
    ld c1x = (2 * x0 + x1) / 3.0;
    ld c1y = (2 * y0 + y1) / 3.0;
    ld c2x = (x0 + 2 * x1) / 3.0;
    ld c2y = (y0 + 2 * y1) / 3.0;
    ld c3x = (x0 + x1) / 2.0 + sqrt(3) * (y0 - y1) / 6.0;
    ld c3y = (y0 + y1) / 2.0 + sqrt(3) * (x1 - x0) / 6.0;

    koch(x0, c1x, y0, c1y, n - 1);
    koch(c1x, c3x, c1y, c3y, n - 1);
    koch(c3x, c2x, c3y, c2y, n - 1);
    koch(c2x, x1, c2y, y1, n - 1);
  }
}

void solve() {
  koch(0, 100, 0, 0, n);
  printVert(100, 0);
}

int main() {
  cout << fixed << setprecision(10);
  cin >> n;
  solve();

  return 0;
}

