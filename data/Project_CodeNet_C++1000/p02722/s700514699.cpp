#include <algorithm>
#include <iostream>

using namespace std;

bool is_ok(long long N, long long k) {
  while (N % k == 0) {
    N /= k;
  }
  return N % k == 1;
}

int main() {
  long long N;
  cin >> N;

  long long ans = 0;
  // N の約数を調べる
  for (long long k = 1; k * k <= N; k++) {
    if (N % k != 0) {
      continue;
    }
    if (k != 1) {
      ans += is_ok(N, k);
    }
    if (N / k != k) {
      ans += is_ok(N, N / k);
    }
  }

  // N-1 の約数を調べる
  for (long long k = 1; k * k <= N - 1; k++) {
    if ((N - 1) % k != 0) {
      continue;
    }
    if (k != 1) {
      ans++;
    }
    if ((N - 1) / k != k) {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}