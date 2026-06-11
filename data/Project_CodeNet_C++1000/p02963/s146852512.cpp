#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;
int m = 1e9;

int main() {
  ll S, x2{m}, x3, y2{1}, y3;
  cin >> S;
  y3 = 1 + (S - 1) / m;
  x3 = m - (S - 1) % m - 1;
  cout << "0 0 " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
}
