#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using lpair = pair<llong, llong>;

#define ALL(x) x.begin(), x.end()

template<typename T>
constexpr T inf = static_cast<T>(pow(10, static_cast<int>(log10(numeric_limits<T>::max())))) + 7;
constexpr llong mod = 1e9+7;

int main() {
  llong N, K;
  vector<llong> A;

  cin >> N >> K;
  A.resize(N);
  for (auto &in: A) {
    cin >> in;
  }

  llong ans = 0;
  for (int i = 0; i < N; ++i) {
    llong all_sum = 0, sum = 0;
    for (int j = 0; j < N; ++j) {
      all_sum += A[j] < A[i];
      if (j > i) {
        sum += A[j] < A[i];
      }
    }

    ans = (ans + (sum * K % mod) + (all_sum * (K * (K - 1) / 2 % mod))% mod) % mod;
  }

  cout << ans << endl;

  return 0;
}