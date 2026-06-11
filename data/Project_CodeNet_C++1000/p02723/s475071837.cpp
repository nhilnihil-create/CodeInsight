#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  string s;
  cin >> s;
  bool a = (s[2] == s[3]);
  bool b = (s[4] == s[5]);
  if(a & b) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
