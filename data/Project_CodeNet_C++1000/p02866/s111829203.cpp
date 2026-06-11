#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

static const ll MOD = 998244353;

ll modPow(ll a, ll b) {
  ll res = 1;
  rep(i, b) {
    res = res * a % MOD;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) {
    int dd;
    cin >> dd;
    // なくても出力時の0以外を含めたチェックではじける
//    if (i == 0 && dd != 0) {
//      cout << 0 << endl;
//      return 0;
//    }
    // 0番目以外が0のとき
    if (i != 0 && dd == 0) {
      cout << 0 << endl;
      return 0;
    }
    d.at(i) = dd;
  }
  map<int, int> mp;
  for (int dd : d) {
    mp[dd]++;
  }
  ll res = 1;
  rep(i, mp.size()) {
    ll tmp = (ll) mp[i];
    // 途中が0なら成立しない
    if (tmp == 0) {
      cout << 0 << endl;
      return 0;
    }
    if (i == 0) {
      if (tmp != 1) {
        cout << 0 << endl;
      }
      continue;
    }
    ll tmp2 = (ll) mp[i - 1];
    res = res * modPow(tmp2, tmp) % MOD;
  }
  cout << res << endl;
  return 0;
}
