#include <bits/stdc++.h>
using namespace std;

long mod = 1000000007;

int main() {
  long n, k;
  cin >> n >> k;
  long ans = 0;
  for (long i = k; i <= n+1; i++) {
    ans += i*(2*n-i+1)/2 - i*(i-1)/2 + 1;
    ans %= mod;
  }
  
  cout << ans;
  
  return 0;
}