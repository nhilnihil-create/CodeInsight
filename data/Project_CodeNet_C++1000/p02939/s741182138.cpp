#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;

  cin >> str;

  int res = 1;
  string prev(str.begin(), str.begin() + 1);
  for (int i = 1; i < str.length();) {
    bool brk = true;

    for (int j = i + 1; j <= str.length(); j++) {
      string tmp(str.begin() + i, str.begin() + j);

      if (prev != tmp) {
        res++;
        prev = tmp;
        i = j;
        brk = false;
        break;
      }
    }

    if (brk) {
      break;
    }
  }

  cout << res << endl;
}