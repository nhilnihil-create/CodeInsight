#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
  string s, ans="No";
  cin >> s;

  if(s[0]==s[1]){
    if(s[2]==s[3]&&s[0]!=s[2]){
      ans="Yes";
    }
  }
  else{
    if(s[1]==s[2]){
      if(s[0]==s[3]&&s[1]!=s[0]){
        ans="Yes";
      }
    }
    else{
      if(s[0]==s[2]){
        if(s[1]==s[3]&&s[0]!=s[1]){
          ans="Yes";
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}