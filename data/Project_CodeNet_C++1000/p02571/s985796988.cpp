#include <iostream>
using namespace std;

int main() {
  string s, t; cin >> s >> t;
  int length = t.length();
  int res = 0;
  
  for (int i = 0; i < s.length() - length + 1; i++) {
    string str = s.substr(i, length);
    int cnt = 0;

    for (int j = 0; j < str.length(); j++) {
      if (str[j] == t[j]) { 
        cnt = cnt + 1;
      }
    }

    if (cnt > res) {
      res = cnt;
    }

  }

  cout << length - res << endl;
}