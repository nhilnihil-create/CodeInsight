#include <iostream>

using namespace std;

typedef long long ll;

ll sq (ll x) {
  return x * x;
}

int main () {
  ll S;
  cin >> S;

  ll p = 0;
  for (ll k = 1 << 30; k != 0; k /= 2) {
    if (sq(p + k) < S) {
      p += k;
    }
  }
  p++;

  cout << 0 << " " << 0 << " "
       << p << " " << sq(p) - S << " "
       << 1 << " " << p << endl;
}
