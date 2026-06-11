#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool flag = true;

  for (int i = 0; i < s.size(); i++){
    if ((i + 1) % 2 == 1 && s[i] == 'L'){
      flag = false;
      break;
    }
    else if ((i + 1) % 2 == 0 && s[i] == 'R'){
      flag = false;
      break;
    }
  }

  if(flag) cout << "Yes";
  else cout << "No";
}