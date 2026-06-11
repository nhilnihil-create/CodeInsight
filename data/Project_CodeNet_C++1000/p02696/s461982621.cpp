#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using ll = long long;
using namespace std;

int main() {
  ll a, b, n, x;
  cin >> a >> b >> n;
  x = b - 1;
  if (x <= n) {
    cout << a * x / b << endl;
    return 0;
  } else {
    x = n;
    cout << a * x / b << endl;
    return 0;
  }
  return 0;
}