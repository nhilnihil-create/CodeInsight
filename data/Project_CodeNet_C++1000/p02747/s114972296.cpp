#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool ans = true;
  if(s.size()%2 == 1) cout << "No" << endl;
  else{
    for(int i = 0; i < s.size(); i++){
      if(i%2 == 0 && s[i] != 'h') ans = false;
      if(i%2 == 1 && s[i] != 'i') ans = false;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}