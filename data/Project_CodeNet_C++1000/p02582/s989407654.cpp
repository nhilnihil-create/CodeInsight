#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  int res = 0;
  int cur = 0;
  cin >> s;

  for (int i = 0; i < 3; i++) {
    if (s[i] == 'R') {
      cur = cur + 1;
    } else {
      if (res < cur) {
        res = cur;
      }
      cur = 0;
    }
  }
  if (res < cur) {
    res = cur;
  }
  cout << res << endl;
  
}