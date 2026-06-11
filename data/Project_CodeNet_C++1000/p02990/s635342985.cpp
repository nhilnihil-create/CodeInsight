#include <iostream>
#include <vector>

using namespace std;

long long M = 1000000000 + 7;

long long factm(long long x) {
  long long result = 1;
  for (long long i = 1; i <= x; i++) {
    result = result * i % M;
  }
  return result;
}

long long powm(long long x, long long p) {
  if (p == 0) return 1;
  long long tmp = x * x % M;
  if (p % 2 == 0) {
    return powm(tmp, p/2);
  } else {
    return x * powm(tmp, (p-1)/2) % M; 
  }
}

long long invfactmc[2001] = {};

long long invfactm(long long x) {
  long long result = 1;
  if (invfactmc[x] != 0) return invfactmc[x];
  for (long long i = 1; i <= x; i++) {
    result = result * powm(i, M-2) % M;
  }
  return invfactmc[x] = result;
}

long long com(long long n, long long k) {
  if (n < k) return 0;
  if (k < 0) return 0;
  return (factm(n)*invfactm(k) % M) * invfactm(n-k) % M;
}


int main() {
  long long N, K;
  cin >> N >> K;
  for (long long i = 1; i <= K; i++) {
    long long result = com(N-K+1, i)*com(K-1, i-1) % M;
    cout << result << endl;
  }
  return 0;
}