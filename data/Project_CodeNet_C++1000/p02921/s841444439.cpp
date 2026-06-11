#include <iostream>
#include <vector>

using namespace std;

int main() {
  char a1, a2, a3;
  char b1, b2, b3;
  cin >> a1 >> a2 >> a3;
  cin >> b1 >> b2 >> b3;
  int ans = int(a1 == b1) + int(a2 == b2) + int(a3 == b3);
  cout << ans << endl;
}