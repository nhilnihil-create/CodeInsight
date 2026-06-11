#include <iostream>

using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  auto money = [](int i) {
    if (i <= 3) {
      return 100000 * (4 - i);
    } else {
      return 0;
    }
  };

  int ans = money(x) + money(y);
  if (x == 1 && y == 1) {
    ans += 400000;
  }
  cout << ans << endl;
}