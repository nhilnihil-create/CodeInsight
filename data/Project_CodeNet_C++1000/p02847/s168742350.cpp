/**
 *    author:  morato
 *    created: 06.09.2020 23:17:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  if (s == "MON") {
    cout << 6 << '\n';
  }
  if (s == "TUE") {
    cout << 5 << '\n';
  }
  if (s == "WED") {
    cout << 4 << '\n';
  }
  if (s == "THU") {
    cout << 3 << '\n';
  }
  if (s == "FRI") {
    cout << 2 << '\n';
  }
  if (s == "SAT") {
    cout << 1 << '\n';
  }
  if (s == "SUN") {
    cout << 7 << '\n';
  }
  return 0;
}