#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool flg = true;
  if(s.size() % 2 != 0) flg = false;
  for(int i = 1; i <= s.size(); i++){
    if(i % 2 == 1){
      if(s[i-1] != 'h') flg = false;
    }else{
      if(s[i-1] != 'i') flg = false;
    }
  }
  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}