#include <iostream>
#define MOD 1000000007
using namespace std;

int main() {
  long long N;
  cin >> N;
  long long A[N];
  for (long long i = 0; i < N; i++) cin >> A[i];
  
  long long pow_2[61];
  for (long long i = 0; i < 61; i++){
    if (i == 0) pow_2[i] = 1;
    else {
      pow_2[i] = pow_2[i - 1] * 2;
    }
  }
  
  long long count[61];
  long long count2[61];
  for (long long i = 0; i < 61; i++) count[i] = count2[i] = 0;
  
  for (long long i = 0; i < N; i++){
    for (long long j = 0; j < 61; j++){
      if (pow_2[60 - j] > A[i]) count[60 - j]++;
      else {
        count2[60 - j]++;
        A[i] -= pow_2[60 - j];
      }
    }
  }
  
  long long res = 0;
  for (long long i = 0; i < 61; i++){
    long long a = pow_2[i];
    a %= MOD;
    a *= (count[i] * count2[i]) % MOD;
    a %= MOD;
    res += a;
    res %= MOD;
  }
  
  cout << res << endl;
}