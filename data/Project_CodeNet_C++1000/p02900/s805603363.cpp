#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  ll A, B;
  cin >> A >> B;
  ll G = __gcd(A, B);
  int cnt = 1;
  for (ll i=2; i*i<=G; ++i) {
    if (G%i == 0) {
      ++cnt;
    }
    while (G%i == 0) {
      G/=i;
    }
  }
  if (G != 1) {
    ++cnt;
  }
  cout << cnt << endl;
  return 0;
}
