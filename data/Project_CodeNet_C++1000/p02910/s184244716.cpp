#include<bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  bool ok = true;
  for (int i = 0; i < s.size(); i++) {
    if (i%2 == 0 && s[i] == 'L') {
      ok = false;
    } else if (i%2 != 0 && s[i] == 'R') {
      ok = false;
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}