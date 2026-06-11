#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

long long mod_pow(long long x, long long y){
  return y ? mod_pow(x * x % MOD, y / 2) * (y % 2 ? x : 1) % MOD : 1;
}
long long combination(long long x, long long y){
  long long n = 1, k = 1;
  for(int i = x; i > y; --i){
    n = n * i % MOD;
    k = k * (i - y) % MOD;
  }
  return n * mod_pow(k, MOD - 2) % MOD;
}
int main(){
  int n, k;
  cin >> n >> k;
  for(int i = 1; i <= k; ++i){
    if(n - k + 1 < i) cout << 0 << endl;
    else cout << (combination(k - 1, i - 1) * combination(n - k + 1, i)) % MOD << endl;
  }
}