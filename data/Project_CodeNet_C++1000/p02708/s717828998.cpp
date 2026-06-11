#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

ll sum(ll l, ll r) {
  return (l + r) * (r - l + 1) / 2;
}

int main() {
  int N, K;
  cin >> N >> K;
  ll ans = 0;
  for (int i = K; i <= N + 1; i++) {
    ll l = sum(0, i - 1);
    ll r = sum(N - i + 1, N);
    ans = (ans + (r - l + 1)) % mod;
  }
  cout << ans << endl;
  return 0;
}