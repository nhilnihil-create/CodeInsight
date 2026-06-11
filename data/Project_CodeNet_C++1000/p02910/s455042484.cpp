#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  bool b = true;
  for (int i = 0; i < s.size(); i++) {
    if (s.at(i) == 'L' && (i+1)%2 == 1) b = false;
    if (s.at(i) == 'R' && (i+1)%2 == 0) b = false;
  }
  if (b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}