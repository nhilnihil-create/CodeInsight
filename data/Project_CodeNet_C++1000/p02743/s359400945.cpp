#include <iostream>

using namespace std;

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  if ((c - (a + b)) < 0) {
    cout << "No";
    return 0;
  }
  c = ((c - (a + b)) * (c - (a + b)));
  if ((4 * a * b) < c) cout << "Yes";
  else cout << "No";
  return 0;
}