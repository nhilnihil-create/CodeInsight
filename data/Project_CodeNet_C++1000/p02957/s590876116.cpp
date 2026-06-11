#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll a, b;
  cin >> a >> b;
  if ((a & 1) != (b & 1)) {
    puts("IMPOSSIBLE");
  } else {
    cout << (a + b) / 2 << endl;
  }
  return 0;
}