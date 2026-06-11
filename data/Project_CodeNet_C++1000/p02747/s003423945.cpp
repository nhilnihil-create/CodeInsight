#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  if(s.size()%2!=0) cout << "No" << endl;
  else {
    bool hitachi = true;
    for(int i=0; i<s.size(); i+=2) {
      if(s.substr(i,2)!="hi") hitachi = false;
    }
    if(hitachi) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}