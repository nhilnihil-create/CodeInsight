#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int a = s.size()-1;
  if (s[a]=='3') cout << "bon" << endl;
  else if (s[a]=='0' || s[a]=='1' || s[a]=='6' || s[a]=='8') cout << "pon" << endl;
  else cout << "hon" << endl;
}