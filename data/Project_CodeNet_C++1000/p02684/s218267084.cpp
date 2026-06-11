#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (ll &x : a) {
    cin >> x;
    --x;
  }
  vector<ll> path;
  path.push_back(0);
  ll now = 0;
  ll count = 0;
  ll loop_start_index;
  set<ll> s;
  while (true) {
    if (s.find(a.at(now)) != s.end()) {
      auto loop_start = find(path.begin(), path.end(), a.at(now));
      loop_start_index = distance(path.begin(), loop_start);
      break;
    }
    now = a.at(now);
    path.push_back(now);
    s.insert(now);
    if (++count == k) {
      cout << ++now << endl;
      return 0;
    }
  }

  ll mod = path.size() - loop_start_index;
  ll remain = k - count;
  --remain;
  cout << ++path.at(loop_start_index + (remain % mod)) << endl;
}
