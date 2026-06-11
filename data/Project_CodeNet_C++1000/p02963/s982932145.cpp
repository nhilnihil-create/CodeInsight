#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll s;
  cin >> s;
  int x1 = 0, y1 = 0;
  int x2 = 1e9, y2 = 1;
  int y3 = (s + x2 - 1) / x2;
  int x3 = x2 * y3 - s;
  printf("%d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3);
  return 0;
}