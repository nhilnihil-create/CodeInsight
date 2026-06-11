#include <iostream>

using namespace std;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int res = 0;
  res += min(a, k);
  k = max(k - a, 0);
  k = max(k - b, 0);
  res -= min(c, k);
  cout << res << endl;
}
