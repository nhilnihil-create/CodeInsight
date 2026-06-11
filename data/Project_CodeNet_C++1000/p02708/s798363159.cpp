#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k; cin >> n >> k;
  long long ans=0;
  for (long long i = k; i <= n+1; i++) {
    ans += (i*n - i*(i-1) + 1)%1000000007 + 1000000007;
    ans%=1000000007;
  }
  cout << (ans%1000000007 + 1000000007) % 1000000007;
  return 0;
}
