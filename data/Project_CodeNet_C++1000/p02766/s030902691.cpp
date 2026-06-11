#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, k, ans = 0;
  cin >> n >> k;
  while (n >= k) { 
    ans++;
    long long res = n % k;
    n = (n - res) / k;
  }
  ans++;
  cout << ans << '\n';
  return 0;
} 