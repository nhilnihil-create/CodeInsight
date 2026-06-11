#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,ss;
  cin >> s >> ss;
  bool t=true;
  for(int i=0;i<s.size();i++){
    if(s[i]!=ss[i]){
      t=false;
      break;
    }
  }
  if(t)cout << "Yes" << endl;
  else cout << "No" << endl;
}
    
