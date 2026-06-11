#include <bits/stdc++.h>
using namespace std;

long f1(long n, int p) {
  if (n == 0) return 0;
  return n / p + f1(n / p, p);
}

long f2(long n, int p) {
  if (n % 2 == 1) {
    return f1(n, p) - f2(n - 1, p);
  }
  long res = f1(n / 2, p);
  if (p == 2) res += n / 2;
  return res;
}

int main() {
  long N;
  cin >> N;
  if (N % 2) return cout << 0 << "\n", 0;
  cout << f2(N, 5) << "\n";
}