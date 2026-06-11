#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll d = c - a - b;
  cout << (d > 0 && 4 * a * b < d * d ? "Yes" : "No") << endl;
}
