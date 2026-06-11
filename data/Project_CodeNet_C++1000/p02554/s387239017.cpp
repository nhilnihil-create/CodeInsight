#include<bits/stdc++.h>
 
using namespace std;
 
const long long mod = 1e9 + 7;
 
long long n;
 
int main() {
  scanf("%lld", &n);
  
  long long sol = 1, a = 1, b = 1;
  
  for (int i = 0; i < n; i++) {
  	sol *= 10;
  	sol %= mod;
    a *= 9;
    a %= mod;
    b *= 8;
    b %= mod;
  }
  
  printf("%lld", (sol - 2 * a + b + 5 * mod) % mod);
  
  return 0;
}