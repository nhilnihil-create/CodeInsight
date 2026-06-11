#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long mx = -1e18;
  for(auto x : {a, b}) {
    for(auto y : {c, d}) {
      mx = max(mx, x * y);
    }
  }
  cout << mx << '\n';
}