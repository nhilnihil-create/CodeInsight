#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll md = 998244353;

int main(int argc, const char *argv[]) {
  ll n, s;
  cin >> n >> s;

  vector<ll> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  ll ans = 0;
  vector<vector<ll>> memo(n + 1, vector<ll>(s + 1, 0));
  memo[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= s; ++j) {
      memo[i][j] += memo[i - 1][j] * 2;
      memo[i][j] %= md;
      if (j - va[i - 1] >= 0) {
        memo[i][j] += memo[i - 1][j - va[i - 1]];
        memo[i][j] %= md;
      }
    }
  }

  cout << memo.back().back() << '\n';
}