#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  string s;
  cin >> s;
  bool ans = true;
  if(s.size() % 2 == 0) {
    for(int i = 0; i < s.size(); i += 2) {
      if (s.at (i) == 'L' || s.at(i + 1) == 'R') ans = false;
    }
  }
  else {
    for(int i = 0; i < s.size() - 1; i += 2) {
      if (s.at (i) == 'L' || s.at(i + 1) == 'R') ans = false;
    }
    if(s.at(s.size() - 1) == 'L') ans = false;
  }
  if (ans == true) cout << "Yes" << endl;
  else cout << "No" << endl;
}
