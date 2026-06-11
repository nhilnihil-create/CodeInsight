#include <bits/stdc++.h>

using namespace std;

#define PRIME 1000000007

typedef long long ll;

ll powMod(ll base, ll pow) {
  ll result = 1;
  
  while (pow != 0) {
    if (pow & 1 == 1) {
      result = result * base;
      result %= PRIME;
    }
    
    base = base * base;
    base %= PRIME;
    
    pow >>= 1;
  }
  
  return result;
}

ll combinationMod(int n, int m) {
  ll result = 1;
  
  for (int i = 1; i <= m; i++) {
    result *= n - m + i;
    result %= PRIME;
    
    result *= powMod(i, PRIME - 2);
    result %= PRIME;
  }
  
  return result;
}

int main() {
  int N, K;
  
  cin >> N >> K;
  
  for (int i = 1; i <= K; i++) {
    cout << (combinationMod(N - K + 1, i) * combinationMod(K - 1, i - 1)) % PRIME << endl;
  }
  
  return 0;
}