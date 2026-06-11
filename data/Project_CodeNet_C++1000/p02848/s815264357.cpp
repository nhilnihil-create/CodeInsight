/**
 *    author:  morato
 *    created: 06.09.2020 23:19:47
**/
#include <bits/stdc++.h>

using namespace std;

void shift(char& ch, int k) {
  while (k--) {
    ch++;
    if (ch > 'Z') {
      ch = 'A';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int k;
  cin >> k >> s;
  for (char& c : s) shift(c, k);
  cout << s << '\n';
  return 0;
}