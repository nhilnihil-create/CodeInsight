#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  a--;b--;c--;d--;
  string s;
  cin >> s;
  bool yes = true;
  if(s[a] == '#' || s[c] == '#') yes = false;
  for(int i=a+1;i<=c;i++) {
    if(s[i] == '#' && s[i-1] == '#') {
      yes = false;
      break;
    }
  }
  if(s[b] == '#' || s[d] == '#') yes = false;
  for(int i=b+1;i<=d;i++) {
    if(s[i] == '#' && s[i-1] == '#') {
      yes = false;
      break;
    }
  }
  if(c > d) {
    bool can = false;
    for(int i=b;i<=d;i++) {
      if(s[i] == '.' && s[i-1] == '.' && s[i+1] == '.') {
        can = true;
      }
    }
    if(!can) yes = false;
  }

  if(yes) cout << "Yes" << endl;
  else cout << "No" << endl;
}