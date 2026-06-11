#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  if(s[0] == s[1] && s[1] == s[2] && s[2] == 'R')
    cout << 3 << endl;
  else if(s[1] != 'R'){
    if(s[0] == 'R' || s[2] == 'R')
      cout << 1 << endl;
    else cout << 0 << endl;
  }
  else if(s[1] == 'R'){
    if(s[0] == 'R' || s[2] == 'R')
      cout << 2 << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}