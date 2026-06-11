#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(max(a * c, a * d), max(b * c, b * d)) << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}