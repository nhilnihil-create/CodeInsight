#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
using namespace std;

const long long MOD = 1000000007;

long long power(long long m, long long n){
    long long res = 1;
    while(n > 0){
        if(n & 1) {
            res = (res * m) % MOD;
        }
        m = (m * m) % MOD;
        n >>= 1;
    }
    return res;
}

long long prev_counts[100000];
int main(){
  int N;
  int K;
  cin >> N >> K;

  long long ans = 0;
  for(int i = K; i >= 1; i--){
    long long cases = (power(K / i, N) - prev_counts[i] + MOD) % MOD;
    ans = (ans + ((long long) i * cases) % MOD) % MOD;

    set <int> divisors;
    for(int j = 1; j < sqrt(i) + 1; j++){
      if(i % j == 0){
        divisors.insert(j);
        divisors.insert(i / j);
      }
    }
    for(auto it = divisors.begin(); it != divisors.end(); it++){
      prev_counts[*it] = (prev_counts[*it] + cases) % MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
