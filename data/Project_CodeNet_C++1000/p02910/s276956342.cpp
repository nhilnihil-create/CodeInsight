#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
 
int main(){
  bool c=true;
  string s;
  cin >> s;
  
  rep(i,s.size()){
    if(i % 2==0){
      if(s[i]=='L') 
        c=false;
    }else{
      if(s[i]=='R') 
        c=false;
    }
  }
  
  if(c==true) 
    cout << "Yes" << endl;
  else 
    cout << "No" << endl;
}