#include <bits/stdc++.h>
using namespace std;
int main() {
  string s; cin >> s;
  bool b = true;
  for(int i=1; i<4; i++){
    if(s[i] == s[i-1]){
      b = false;
      break;
    }
  }
  if(b)cout << "Good" << endl;
  else cout << "Bad" << endl;
}