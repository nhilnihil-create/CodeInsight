#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void) {
  ll k;
  cin >> k;
  ll a = 7;
  for (int i = 0; i <= k; i++) {
    a = a % k;
    if (a == 0) {
      cout << i + 1 << endl;
      return 0;
    }
    a = a * 10 + 7;
  }
  cout << "-1" << endl;
  return 0;
}