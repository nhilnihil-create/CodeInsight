#include <iostream>

using namespace std;

int main() {
  int cnt = 0, res = 0;
  for (int i = 0; i < 3; ++i) {
    char c;
    cin >> c;
    if (c == 'R') cnt++;
    else cnt = 0;
    res = max(cnt, res);
  }
  cout << res << endl;
}
