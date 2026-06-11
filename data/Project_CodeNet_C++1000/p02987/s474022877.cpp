#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int cnt = 1;
  for (int i = 1; i <4; i++){
    cnt++;
    if(s[0] == s[i]) break;
  }
  if(cnt == 2){
    if(s[2] == s[3] && s[0] != s[2]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }else if (cnt == 3){
    if(s[1] == s[3] && s[0] != s[1]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }else if (cnt == 4){
    if(s[1] == s[2] && s[0] != s[1]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }else cout << "No" << endl;
}
