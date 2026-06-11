#include <iostream>

using namespace std;

int main() {
  long long x, k, d;
  cin >> x >> k >> d;
  x = abs(x);

  if (k <= x / d) {
    cout << x - k * d << endl;
    return 0;
  }

  k = (k - x / d) % 2;
  x %= d;

  for (int i = 0; i < k; ++i) x = abs(x - d);

  cout << x << endl;
}
