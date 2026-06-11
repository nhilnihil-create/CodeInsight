#include <bits/stdc++.h>

//#include <atcoder/all>

using namespace std;
// using namespace atcoder;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<int> dcnt(n - 1, 0);  // D = i となる頂点の個数
  int mxd = 0;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;

    if (i == 0 && d != 0) {
      // 頂点1は距離0のみ
      cout << 0 << endl;
      return 0;
    }

    if (i != 0 && d == 0) {
      // 頂点2~は距離1~のみ
      cout << 0 << endl;
      return 0;
    }

    mxd = max(d, mxd);
    dcnt[d]++;
  }

  dcnt[0] = 1;
  ll ans = 1;
  for (int i = 1; i <= mxd; i++) {
    for (int j = 0; j < dcnt[i]; j++) {
      // D = i なる頂点ひとつ (j) に対して
      // D = i-1 となる頂点の個数 dcnt[i-1] だけ親がある
      ans *= dcnt[i - 1];
      ans %= 998244353;
    }
  }

  cout << ans << endl;
}