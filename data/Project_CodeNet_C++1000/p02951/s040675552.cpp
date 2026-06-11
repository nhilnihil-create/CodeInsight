#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

void solve(ll A, ll B, ll C) {
  ll ans = max(0ll, C - A + B);
  cout << ans << endl;
}

int main() {
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  ll C;
  cin >> C;
  solve(A, B, C);
  return 0;
}
