#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, k, ans;
  cin >> n >> k;
  vector<ll> a(n);
  rep (i, n) {
    cin >> a[i];
  }
  ll inA = 0;
  for (int i = 0; i < n ;i++) {
    for (int j = i + 1; j < n; j++){
      if (a[i] > a[j]) inA++;
    }
  }
  ans = 0;
  rep (i, k / 100000) {
    ans  += 100000 * inA;
    ans %= 1000000007;
  }
  ans += (k % 100000) * inA;
  ans %= 1000000007;
  ll inK = 0;
  for (int i = 0; i < n ;i++) {
    for (int j = 0; j < n; j++){
      if (a[i] > a[j]) inK++;
    }
  }
  ll loop = k * (k - 1) / 2;
  loop %= 1000000007;
  rep (i, loop / 100000) {
    ans += 100000 * inK;
    ans %= 1000000007;
  }
  ans += inK * (loop % 100000);
  ans %= 1000000007;
  cout << ans << endl;
  return 0;
}
