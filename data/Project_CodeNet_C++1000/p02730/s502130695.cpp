#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  bool sp = true;
  int mi = s.size()/2;
  rep(i, mi) {
    if (s[i] != s[mi-1-i]) sp = false;
    if (s[i] != s[mi+1+i]) sp = false;
    if (s[i] != s[s.size()-1-i]) sp = false;
  }
  if (sp) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}