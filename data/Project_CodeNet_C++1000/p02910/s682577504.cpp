#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int len = s.size();
  bool jud = true;
  for (int i=0; i<len; i++){
    if (i%2==0){ //奇数番め
      if (s[i]!='R' && s[i]!='U' && s[i]!='D') jud = false;
    }
    else{
      if (s[i]!='L' && s[i]!='U' && s[i]!='D') jud = false;
    }
  }
  if (jud == true) cout << "Yes";
  else cout << "No";
}