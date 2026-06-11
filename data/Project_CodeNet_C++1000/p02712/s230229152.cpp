#include <bits/stdc++.h>
using namespace std;

long aps(long a, long d, long n) {
  return n * (2 * a + (n - 1) * d) / 2;
}

int main() {
  int N;
  cin >> N;
  long ans = aps(1, 1, N);
  ans -= aps(3, 3, N / 3);
  ans -= aps(5, 5, N / 5);
  ans += aps(15, 15, N / 15);
  cout << ans << "\n";
}