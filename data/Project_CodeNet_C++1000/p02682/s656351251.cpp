#include <iostream>

using namespace std;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  cout << min(a, k) - max(k - a - b, 0) << endl;
}
