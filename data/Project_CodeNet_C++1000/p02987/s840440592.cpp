#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  string s, ans = "No";
  cin >> s;
  if(s.at(0) == s.at(1) && s.at(2) == s.at(3) && s.at(1) != s.at(2)) ans = "Yes";
  if(s.at(0) == s.at(3) && s.at(2) == s.at(1) && s.at(1) != s.at(0)) ans = "Yes";
  if(s.at(0) == s.at(2) && s.at(1) == s.at(3) && s.at(1) != s.at(0)) ans = "Yes";
  cout << ans << endl;
}