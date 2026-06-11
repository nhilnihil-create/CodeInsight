#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //freopen("data.in", "r", stdin);

  string s;
  cin >> s;
  int max_ = s.length()/2;
  int c = 0;
  int i = 0, l = s.length()-1;
  while (max_--) {
    if (s[i] != s[l-i]) c++;
    i++;
  }

  cout << c << endl;

  return 0;
}