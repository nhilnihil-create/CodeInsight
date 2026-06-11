#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

template <class T>
map<int, int> prime_factorization(T N) {
  map<int, int> m;
  int s = sqrt(N) + 1;
  vector<bool> sieve(s + 1, true);
  for (int i = 2; i <= s; ++i) {
    if (!sieve[i]) {
      continue;
    }
    while (N % i == 0) {
      ++m[i];
      N /= i;
    }
    if (N == 1) break;
    for (int j = 2 * i; j < s; j += i) sieve[j] = false;
  }
  if (N != 1) ++m[N];
  return m;
}

int main() {
  long long A, B;
  cin >> A >> B;
  cout << prime_factorization(gcd(A, B)).size() + 1 << endl;
}
