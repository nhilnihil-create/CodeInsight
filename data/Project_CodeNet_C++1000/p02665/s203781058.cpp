#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
long long longpow(long long n, long long a, long long mod) {
  if (a == 0) return 1;
  if (a == 1) return n % mod;
  if (a % 2 == 1) return (n * longpow(n, a - 1, mod)) % mod;
  ll t = longpow(n, a / 2, mod) % mod;
  return (t * t) % mod;
}
int main() {
  int N;
  cin >> N;
  vector<ll> A(N + 2);
  REP(i, N + 1) cin >> A[i];
  ll ans = 0;
  vector<ll> L(N + 2), R(N + 2);
  L[N] = A[N], R[N] = A[N];
  for (int i = N - 1; i >= 0; i--) {
    L[i] = A[i] + (L[i + 1] + 1) / 2;
    R[i] = A[i] + R[i + 1];
  }
  if (L[0] != 1) {
    cout << -1 << endl;
    return 0;
  }
  ll current = 1;
  REP(i, N + 1) {
    ans += current;
    current -= A[i];
    current = min(current * 2, R[i + 1]);
  }

  cout << ans << endl;
}