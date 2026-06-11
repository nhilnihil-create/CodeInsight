#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>

using namespace std;

int main() {
  string s,t;
  cin >> s >> t;

  if(t.size() == s.size() + 1) {
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == t[i]) continue;
      else cout << "No" << endl; goto Exit;
    }
  }
  else {
    cout << "No" << endl; 
    goto Exit;
  }

  cout << "Yes" << endl;
  Exit:;
}