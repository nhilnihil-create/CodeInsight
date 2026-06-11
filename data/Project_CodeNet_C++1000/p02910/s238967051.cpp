#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool c = true;
  int n = s.size();
  for(int i = 0;i < n;i++) {
    if(i % 2 == 0) {
      if(s[i] == 'L') {
        c = false;
        break;
      }
    } else {
      if(s[i] == 'R') {
        c = false;
        break;
      }
    }
  }
  cout << (c ? "Yes" : "No") << endl;
}