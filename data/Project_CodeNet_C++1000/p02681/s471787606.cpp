#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  if (s.size() + 1 == t.size()) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s.at(i) == t.at(i)) {
        count++;
      }
      else {
        cout << "No" << endl;
        return 0;
      }  
    }
    if (s.size() == count) cout << "Yes" << endl;
  } else cout << "No" << endl;
}