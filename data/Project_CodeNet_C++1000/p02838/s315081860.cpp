#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll N;
  cin >> N;
  ll A[N];
  ll ans = 0;
  ll pw[62];
  pw[0] = 1;
  for (int i = 1; i < 62; i++) {
    pw[i] = pw[i-1] * 2;
    pw[i] %= Mod;
  }
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (ll bit = 0; bit < 60; bit++) {
    ll one = 0;
    ll zero = 0;
    for (ll i = 0; i < N; i++) {
      if ((A[i] & (1LL << bit))) {
        one++;
      } else {
        zero++;
      }
    }
    ll res = (one * zero);
    res %= Mod;
    res *= pw[bit];
    res %= Mod;
    ans += res;
    ans %= Mod;
  }
  cout << ans << endl;
  return 0;
}