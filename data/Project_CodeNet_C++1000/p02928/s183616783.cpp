#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll c = 0, c2 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j]) {
        c++;
      } else if (a[i] < a[j]) {
        c2++;
      }
    }
  }
  k = k % MOD;
  ll ans = c * k;
  ll kk = (k * (k - 1) / 2) % MOD;
  ans += (c + c2) * kk;
  ans = ans % MOD;
  cout << ans << '\n';
  return 0;
}