#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

signed main() {
  string s;
  cin >> s;

  bool flag = false;
  if(s[0] == s[1] && s[2] == s[3]) flag = true;
  if(s[0] == s[2] && s[1] == s[3]) flag = true;
  if(s[0] == s[3] && s[1] == s[2]) flag = true;

  if(s == string((int)s.size(), s[0])) flag = false;

  if(flag) cout << "Yes" << '\n';
  else cout << "No" << '\n';

}
