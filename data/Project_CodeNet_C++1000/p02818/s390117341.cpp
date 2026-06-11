#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;

int main() {
  ll A, B, K;
  cin >> A >> B >> K;

  ll take = min(A, K);
  A -= take;
  K -= take;

  if (K > 0) B -= K;
  if (B < 0) B = 0;

  cout << A << " " << B << endl;

  return 0;
}
