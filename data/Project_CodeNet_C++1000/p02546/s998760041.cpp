/**
 *    author:  morato
 *    created: 19.09.2020 17:25:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  if (s.back() == 's') {
    cout << s << "es\n";
  } else {
    cout << s << 's' << '\n';
  } 
  return 0;
}