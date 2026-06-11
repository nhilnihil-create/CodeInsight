#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s, p;
  cin >> s;
  cin >> p;

  for (size_t i = 0; i < s.size(); ++i) {
    bool m = true;
    for (size_t j = 0; j < p.size(); ++j) {
      int k = j + i;
      if (j + i >= s.size()) {
        k = j + i - s.size();
      }
      if (s[k] != p[j]) {
        m = false;
        break;
      }
    }
    if (m) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
  return 0;
}