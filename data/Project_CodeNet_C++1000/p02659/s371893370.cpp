#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll a;
  double b;
  cin >> a >> b;
  ll bl = llround(b * 100);
  ll ans = a * bl / 100;
  cout << ans << endl;
}