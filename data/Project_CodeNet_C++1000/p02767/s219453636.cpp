#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

const ll INF = 1ll << 60;

int main() {
  ll m = INF;
  int n;
  cin >> n;
  vector<int> xs(n);
  rep(i, n) cin >> xs[i];
  for (int i = 1; i <= 100; i++) {
    ll sum = 0;
    rep(j, n) { sum += (xs[j] - i) * (xs[j] - i); }
    m = min(m, sum);
  }
  cout << m << endl;
  return 0;
}
