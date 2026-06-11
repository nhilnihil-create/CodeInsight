#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s,t;
  cin >> s >> t;
  string t_sub = t.substr(0, s.size());
  bool res = false;
  if (s == t_sub && t.size() == s.size()+1) res = true;
  if (res) {
      cout << "Yes" << endl;
  } else {
      cout << "No" << endl;
  }
  return 0;
}