#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool ans = true;
  
  for (int i = 0;i < s.size();i++){
    if (i%2 == 0){
      if (s[i] != 'R' && s[i] != 'U' && s[i] != 'D'){
        ans = false;
        break;
      }
    }
    else{
      if (s[i] != 'L' && s[i] != 'U' && s[i] != 'D'){
        ans = false;
        break;
      }
    }
  }
  
  if (ans){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}
