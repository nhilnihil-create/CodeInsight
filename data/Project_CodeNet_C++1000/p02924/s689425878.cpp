/**
 *    author:  lets
 *    created: 2020-06-07 14:18:59 JST
 **/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  unsigned long long ans = (n * (n + 1)) / 2 - n;
  cout << ans << '\n';
  return 0;
}