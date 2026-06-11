#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
  ll n, a, ans = 1;
  cin >> n;
  vector<ll> cnt(n + 1, 0);
  rep(i, n) {
    cin >> a;
    if (a == 0)
      ans *= 3 - cnt[a];
    else
      ans *= cnt[a - 1] - cnt[a];
    ans %= mod;
    cnt[a]++;
  }
  cout << ans << endl;
  return 0;
}