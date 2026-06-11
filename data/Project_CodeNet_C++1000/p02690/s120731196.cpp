#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll X;
const ll L = 300;

int main() {
  cin >> X;
  for (ll a = -L; a <= L; ++a) {
    for (ll b = -L; b <= L; ++b) {
      if (a * a * a * a * a - b * b * b * b * b == X) {
        cout << a << " " << b << endl;
        return 0;
      }
    }
  }
  return 0;
}
