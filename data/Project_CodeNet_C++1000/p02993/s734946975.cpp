#include <bits/stdc++.h>
using namespace std;
signed main(){
  string s;
  cin>>s;
  bool check=false;
  for(int i = 0; i<3;i++){
    if(s[i]==s[i+1])check=true;
  }
  if(check)cout<<"Bad"<<endl;
  else cout<<"Good"<<endl;
}
