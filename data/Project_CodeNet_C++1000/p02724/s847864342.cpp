#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  ll x;
  cin >> x;
  ll a = 0;
  ll b = x / 500;
  a += 1000 * b;
  x -= b * 500;
  b = x / 5;
  a += 5 * b;
  cout << a << endl;
  return 0;
}