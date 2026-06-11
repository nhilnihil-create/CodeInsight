#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll md = 998244353;

ll solve(vector<ll> &va, ll s, ll offset, vector<vector<ll>> &memo) {
  if (offset == va.size()) {
    return s == 0;
  }

  if (memo[s][offset] == -1) {
    ll ans = solve(va, s, offset + 1, memo) * 2;
    if (s - va[offset] >= 0) {
      ans += solve(va, s - va[offset], offset + 1, memo);
    }

    ans %= md;
    memo[s][offset] = ans;
  }

  return memo[s][offset];
}

int main(int argc, const char *argv[]) {
  ll n, s;
  cin >> n >> s;

  vector<ll> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  ll ans = 0;
  vector<vector<ll>> memo(s + 1, vector<ll>(n + 1, -1));
  cout << solve(va, s, 0, memo) << '\n';
}