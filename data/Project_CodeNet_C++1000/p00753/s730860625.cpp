#include <algorithm>
#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <string>
#include <vector>

#define el endl
#define fd fixed
#define INF INT_MAX/2-1
#define pb push_back

using namespace std;

vector<int> primes;

bool isPrime(int p) {
  for (int i = 0; i < primes.size(); i++) {
    if (p % primes[i] == 0) {
      return false;
    }
  }
  return true;
}

void makePrimes(int n) {
  primes.pb(2);
  for (int i = 3; i < n; i++) {
    if (isPrime(i)) {
      primes.pb(i);
    }
  }
}

int main() {
  makePrimes(123456*2);
  int n, cnt;
  while (cin >> n, n) {
    cnt = 0;
    for (int i = 0; i < primes.size(); i++) {
      if (n < primes[i] && primes[i] <= 2*n) cnt++;
    }
    cout << cnt << el;
  }
}