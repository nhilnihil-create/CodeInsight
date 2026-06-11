#include <bits/stdc++.h>
using namespace std;

int main() {
  long n;
  cin >> n;
  
  long long ans = 0;
  for (long i = 1; i <= n; i++) {
    if (i%3 && i%5) ans += i;
  }
  
  cout << ans;
  
  return 0;
}