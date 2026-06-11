#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  bool flag = true;
  rep(i, s.size()) {
    if (i % 2 != 0) {
      if (s[i] == 'R')
        flag = false;
    } else {
      if (s[i] == 'L')
        flag = false;
    }
  }
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
