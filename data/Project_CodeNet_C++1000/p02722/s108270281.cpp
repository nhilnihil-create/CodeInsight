#include <algorithm>
#include <iostream>

using namespace std;

long long N;
bool is_ok(long long X, long long k) {
  if (k == 1) {
    return false;
  }
  while (X % k == 0) {
    X /= k;
  }
  return X % k == 1;
}

int main() {
  cin >> N;

  long long ans = 0;

  for (long long k = 1; k * k <= N; k++) {
    if (N % k != 0) {
      continue;
    }
    if (k != 1) {
      ans += is_ok(N, k);
    }
    if (N / k > k) {
      ans += is_ok(N, N / k);
    }
  }

  for (long long k = 1; k * k <= N - 1; k++) {
    if ((N - 1) % k != 0) {
      continue;
    }
    if (k != 1) {
      ans++;
    }
    if ((N - 1) / k > k) {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}