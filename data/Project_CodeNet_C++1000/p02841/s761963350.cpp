#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int m1, d1, m2, d2;
  cin >> m1 >> d1 >> m2 >> d2;
  if (m2 > m1) cout << 1 << '\n';
  else cout << 0 << '\n';
  return 0;
}
