#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll N;
  ll K;
  cin >> N >> K;
  ll A[N];
  ll T[N];
  ll U[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    T[i] = 0;
    U[i] = 0;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (A[i] > A[j]) {
        T[i]++;
        if (i < j) {
          U[i]++;
        }
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ll a = (K - 1) * (T[i]);
    a %= Mod;
    a += 2 * U[i];
    a %= Mod;
    a *= K;
    a %= Mod;
    a *= 500000004;
    a %= Mod;
    ans += a;
    ans %= Mod;
  }
  cout << ans << endl;
  return 0;
}
