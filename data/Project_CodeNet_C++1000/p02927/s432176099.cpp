#include <iostream>

using namespace std;

int main() {
  int M, D, ans{};
  cin >> M >> D;
  for (int i = 1; i <= M; ++i) {
    for (int j = 2; j <= D; ++j) {
      if (j / 10 < 2 || j % 10 < 2) continue;
      if (i == j % 10 * (j / 10)) ++ans;
    }
  }
  cout << ans << endl;
}
