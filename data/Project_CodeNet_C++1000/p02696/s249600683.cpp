#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll a, b, n;
  cin >> a >> b >> n;
  if (n > b - 1) {
    n = b - 1;
  }
  a *= n;
  a /= b;
  cout << a << "\n";

  return 0;
}
