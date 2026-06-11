#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  string s;
  cin >> s;
  vector<string> v = {"RUD", "LUD"};
  bool dance = true;
  for (int i = 0; i < s.length(); i++) 
    if (v[i & 1].find(s[i]) == string::npos)
      dance = false;
  cout << (dance ? "Yes\n" : "No\n");
  return 0;
}