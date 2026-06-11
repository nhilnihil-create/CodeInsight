#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1000000007;

int main() {
  ll N, K, S, T, ans{};
  cin >> N >> K;
  vector<int> A(N);
  ll P = K * (K+1) / 2 % MOD;
  ll Q = K * (K-1) / 2 % MOD;
  for (int &a: A) cin >> a;
  for (int i = 0; i != N; ++i) {
    S = T = 0;
    for (int j = 0; j != N; ++j)
      if (A[i] > A[j]) ++(i < j ? S : T);
    ans = (ans + S * P + T * Q) % MOD;
  }
  cout << ans << endl;
}
