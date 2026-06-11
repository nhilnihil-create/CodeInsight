#include <bits/stdc++.h>
using namespace std;

int64_t gcd(int64_t x, int64_t y) {
  if (x % y == 0) {
    return y;
  }else {
    return gcd(y, x % y);
  }
}

int main() {
  int64_t a, b;
  int64_t c, d;
  cin >> a >> b >> c >> d;
  int64_t count = 0, counta_1 = 0, countb = 0;//答え、cでもdでも割り切れない1～a(b)の数
  //1～bのb個の数でc,dの倍数でないもの=b-(cの倍数)-(dの倍数)+(cかつdの倍数)
  int64_t lcm = c * d / gcd(c, d);
  countb = b - b / c - b / d + b / lcm;
  counta_1 = (a - 1) - (a - 1) / c - (a - 1) / d + (a - 1) / lcm;
  count = countb - counta_1;
  cout << count;
}