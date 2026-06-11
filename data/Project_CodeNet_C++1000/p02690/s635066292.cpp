#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll x;
  cin >> x;
  vector<ll> p(401, 0);

  // 先に5乗を計算する
  for (ll i = 0; i < 201; i++) {
    p.at(i + 200) = i * i * i * i * i;
    p.at(-i + 200) = -p.at(i + 200);
  }

  // 該当の整数の組を探す
  rep(i, 401) rep(j, 401) {
    if (p.at(i) - p.at(j) == x) {
      cout << i - 200 << " " << j - 200 << endl;
      return 0;
    }
  }
  return 0;
}