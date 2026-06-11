#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
long long longpow(long long n, long long a) {
  if (a == 0) return 1;
  if (a == 1) return n;
  if (a % 2 == 1) return (n * longpow(n, a - 1));
  ll t = longpow(n, a / 2);
  return (t * t);
}
const int mod = 1e9 + 7;
struct Combination {
  // Combnation(x)　xCxまでを生成
  // RetCombination(n,r) nCrを返す
  vector<vector<long long>> combination;
  Combination(int x) {
    combination.resize(x + 1);
    for (int i = 0; i < x + 1; i++) {
      combination[i].resize(x + 1);
    }
    combination[0][0] = 1;
    for (int i = 0; i < x; i++) {
      for (int j = 0; j <= i; j++) {
        combination[i + 1][j] += combination[i][j];
        combination[i + 1][j + 1] += combination[i][j];
        combination[i + 1][j] %= mod;
        combination[i + 1][j + 1] %= mod;
      }
    }
  }
  long long RetCombination(int n, int r) { return combination[n][r]; }
};
int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  vector<ll> bits(60, 0);
  REP(j, N) {
    for (int i = 59; i >= 0; i--) {
      if (longpow(2, i) <= A[j]) {
        bits[i]++;
        A[j] -= longpow(2, i);
      }
    }
  }
  ll ans = 0;
  REP(i, 60) {
    if (bits[i] == 0 || bits[i] == N) continue;
    ans += (longpow(2, i) % mod) * ((bits[i] * (N - bits[i])) % mod);
    ans %= mod;
  }
  cout << ans << endl;
}