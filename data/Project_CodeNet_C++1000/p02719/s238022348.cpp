#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  long long ans;
  if(n >= k) n %= k;
  ans = min(n, (k - n));
  cout << ans << endl;
}