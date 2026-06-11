#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  if (a == 1) ans += 3e5;
  else if (a == 2) ans += 2e5;
  else if (a == 3) ans += 1e5;
  if (b == 1) ans += 3e5;
  else if (b == 2) ans += 2e5;
  else if (b == 3) ans += 1e5;
  cout << ((ans == 6e5) ? (int)(10e5) : ans) << endl;
  return 0;
}
