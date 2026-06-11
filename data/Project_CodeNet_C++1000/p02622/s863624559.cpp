#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;

  int cnt = 0;
  for (const char c : s) {
    char t;
    cin >> t;
    if (t != c) cnt++;
  }

  cout << cnt << endl;
}
