#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a;
  double b;
  cin >> a >> b;
  ll c = round(b * 100.0);
  cout << a * c / 100LL << '\n';
  return 0;
}
