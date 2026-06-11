#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  ll L, R;
  cin >> L >> R;

  // あまり同士の掛け算
  // 余りを最小にする
  ll ans =2020;
  ll r = min(L + 2019, R);
  for (ll i = L; i < r; ++i) {
    for (ll j = i + 1; j <= r; ++j) {
      ans = min(ans, i * j % 2019);
    }
  }


  cout << ans << endl;

  return 0;
}