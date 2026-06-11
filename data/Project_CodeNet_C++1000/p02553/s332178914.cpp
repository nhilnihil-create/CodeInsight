#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long m = max(a * c, b * d);
  m = max(m, c * b);
  m = max(m, a * d);
  cout << m << endl;
}
