#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  a--;
  b--;
  c--;
  d--;
  bool canGo = true;
  bool previousIsIwa = false;
  int cnt = 0;
  bool canChange = false;
  rep(i, n) {
    // 岩が並んでいたら駄目
    if (i > a && i < d) {
      if (s[i] == '#') {
        if (previousIsIwa) {
          canGo = false;
        }
        previousIsIwa = true;
      } else {
        previousIsIwa = false;
      }
    }
    // すぬけ君とふぬけ君の順番変われるか
    // c > d の場合のみ考慮
    if (i >= b - 1 && i <= d + 1) {
      if (s[i] == '.') {
        if (cnt >= 2) {
          canChange = true;
        }
        cnt++;
      } else {
        cnt = 0;
      }
    }
  }
  bool ok = canGo;
  if (c > d) {
    ok = ok && canChange;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
