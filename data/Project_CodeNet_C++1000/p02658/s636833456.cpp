#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(void) {
  ll n;
  cin >> n;
  ll row[n];
  ll result = 1;
  for (int i = 0; i < n; i++) {
    cin >> row[i];
    if (row[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if ((ll)1e+18 / result < row[i]) {
      cout << -1 << endl;
      return 0;
    }
    result *= row[i];
  }
  if (result > (ll)1e+18) result = -1;
  cout << result << endl;
  return 0;
}
