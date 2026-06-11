#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;
  if (s.back() == 's') cout << s + "es";
  else cout << s + "s";
}