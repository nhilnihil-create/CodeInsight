#include <bits/stdc++.h>
using namespace std;
 
string s;
 
int main(){
  cin >> s;
  string res = "No";
  if(s[0] == s[1]){
    if(s[2] == s[3]){
      if(s[0] != s[2]){
        res = "Yes";
      }
    }
  }else if(s[0] == s[2]){
    if(s[1] == s[3]){
      if(s[0] != s[1]){
        res = "Yes";
      }
    }
  }else if(s[0] == s[3]){
    if(s[1] == s[2]){
      if(s[0] != s[1]){
        res = "Yes";
      }
    }
  }
  cout << res << endl;
}