#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;

int main() {
  int n;
  cin >> n;

  vector<int> d(n);
  for (int i = 0; i < d.size(); ++i)
    cin >> d[i];

  if (d.front() != 0) {
    cout << 0 << endl;
    return 0;
  }

  sort(d.begin(), d.end());

  ll ans = 1;
  ll cnt_p = 1; // parent
  ll cnt_c = 0; // child
  int depth = 1;

  auto f = [&]() {
    ll tmp = 1;
    for (int i = 0; i < cnt_c; ++i)
      tmp = tmp * cnt_p % mod;
    ans = ans * tmp % mod;
  };

  for (int i = 1; i < d.size(); ++i) {
    if (d[i] == depth) {
      ++cnt_c;
      continue;
    }
    if (d[i] != depth + 1) {
      ans = 0;
      break;
    }
    f();
    cnt_p = cnt_c;
    cnt_c = 1;
    depth = d[i];
  }
  if (ans != 0)
    f();

  cout << ans << endl;
}