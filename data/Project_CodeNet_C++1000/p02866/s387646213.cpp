#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long mod_pow(long long x, long long n) {
  if (n == 0)
    return 1;
  return n % 2 == 1 ? mod_pow(x * x % MOD, n / 2) * x % MOD
                    : mod_pow(x * x % MOD, n / 2);
}

int main() {
  int N;
  cin >> N;
  vector<long long> D(N);
  for (int i = 0; i < N; ++i) {
    cin >> D[i];
  }

  map<long long, int> m;
  for (int i = 0; i < N; ++i) {
    ++m[D[i]];
  }

  long long ans = D[0] == 0 && m[0] == 1 ? 1 : 0;
  for (size_t i = 2; i < m.size(); ++i) {
    ans = ans * mod_pow(m[i - 1], m[i]) % MOD;
  }

  cout << ans << endl;
}
