#include<bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long mod_pow(long long x, long long y){
  return y ? mod_pow(x * x % MOD, y >> 1) * (y & 1 ? x : 1) % MOD : 1;
}

long long combination(long long n, long long k){
  k = min(k, n - k);
  long long x = 1, y = 1;
  for(long long i = 0; i < k; ++i){
    x = x * (n - i) % MOD; 
    y = y * (i + 1) % MOD;
  }
  return x * mod_pow(y, MOD - 2) % MOD;
}
int main(){
  long long n, a, b; cin >> n >> a >> b;
  long long all_combination = mod_pow(2, n) - 1;
  long long minus1 = combination(n, a);
  long long minus2 = combination(n, b);
  all_combination += MOD * 2; 
  cout << (all_combination - minus1 - minus2) % MOD << endl;
}