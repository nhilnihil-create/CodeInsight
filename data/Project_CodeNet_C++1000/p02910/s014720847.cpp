#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  bool ok = true;
  rep(i,s.size()) {
    if(s[i] == 'U' || s[i] == 'D') continue;
    if(i % 2 == 0) {
      if(s[i] != 'R') ok = false;
    }else{
      if(s[i] != 'L') ok = false;
    }
  }
  cout << (ok? "Yes":"No") << endl; 
  return 0;
}