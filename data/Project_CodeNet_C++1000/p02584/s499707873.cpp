#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const long long mod = 1e9+7;
//////////////////////////////////

int main() {
  long long x, k, d; cin >> x >> k >> d;
  x = abs(x);
  k -= x / d;
  x -= (x / d) * d;
  if (k < 0) {
    x += d * abs(k);
  } else {
    if (k % 2 == 1) {
      x -= d;
    }
  }
  cout << abs(x) << endl;

  return 0;
}

// EOF