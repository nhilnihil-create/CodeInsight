#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

vector<pair<long long, long long> > prime_factorize(long long N) {
  vector<pair<long long, long long> > res;
  for (long long a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    long long ex = 0;  // 指数

    // 割れる限り割り続ける
    while (N % a == 0) {
      ++ex;
      N /= a;
    }

    // その結果を push
    res.push_back({a, ex});
  }

  // 最後に残った数について
  if (N != 1) res.push_back({N, 1});
  return res;
}

int main() {
  ll a, b;
  cin >> a >> b;

  using pll = pair<ll, ll>;

  vector<pll> aa = prime_factorize(a);

  vector<pll> bb = prime_factorize(b);

  ll ans = 1;

  map<ll, ll> mp;

  for (int i = 0; i < aa.size(); i++) {
    mp[aa[i].first]++;
  }
  for (int i = 0; i < bb.size(); i++) {
    mp[bb[i].first]++;
  }

  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it->second == 2) {
      ans++;
    }
  }

  cout << ans << endl;
}