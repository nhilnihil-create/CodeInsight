/** 
 * THIS IS MOOONI'S CODE !
 * HACK IT IF YOU CAN !
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  if ((int) s.size() % 2 == 1) {
    cout << "No" << '\n';
    return 0;
  }
  for (int i = 1; i < (int) s.size(); i += 2) {
    if (s[i] != 'i' || s[i - 1] != 'h') {
      cout << "No" << '\n';
      return 0;
    }
  }
  cout << "Yes" << '\n';
  return 0;
}