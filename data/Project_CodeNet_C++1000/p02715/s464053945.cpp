#include <iostream>
#include <cmath>
using namespace std;
#define MOD 1000000007

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
  long long N, K;
  cin >> N >> K;
  
  long long count = modpow(K, N);
  long long sum[K];
  for (int i = 0; i < K; i++) sum[i] = 1;
  
  for (int i = 2; i <= K; i++){
    count += (i - sum[i - 1]) * modpow(K / i, N);
    count %= MOD;
    for (int j = 2; j <= K / i; j++){
      sum[j * i - 1] += i - sum[i - 1];
    }
  }
  
  cout << count << endl;
}