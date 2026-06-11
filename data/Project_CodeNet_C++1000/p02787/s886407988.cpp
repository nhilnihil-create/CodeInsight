#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

typedef long long ll;

using namespace std;

const int INF = 1 << 30;

template<class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int h, n;
  cin >> h >> n;
  vector<int> a(n);
  vector<int> b(n);
  int aMax = 0;
  rep(i, n) {
    int aa, bb;
    cin >> aa >> bb;
    aMax = max(aMax, aa);
    a.at(i) = aa;
    b.at(i) = bb;
  }

  // dp[i] 体力を i 削るときの最小の消費魔力
  int hh = h + aMax;
  vector<int> dp(hh, INF);
  dp.at(0) = 0;

  for (int i = 0; i < hh; i++) {
    for (int j = 0; j < n; j++) {
      int aa = a.at(j);
      int bb = b.at(j);
//      // 貰うDP
//      if (i - aa >= 0) {
//        chmin(dp.at(i), dp.at(i - aa) + bb);
//      }
      // 配るDP
      if (i + aa < hh) {
        chmin(dp.at(i + aa), dp.at(i) + bb);
      }
    }
  }
  int res = INF;
  for (int i = h; i < hh; i++) {
    chmin(res, dp.at(i));
  }
  cout << res << endl;
  return 0;
}
