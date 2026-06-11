#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i< (n);i++)
using namespace std;

int main() {
  string s;
  cin>>s;
  bool ok=true;
  for(int i=0;i<s.size();i+=2){
    if(s[i]!='R'&& s[i]!='U'&& s[i]!='D')ok=false;
  }
  
  for(int i=1;i<s.size();i+=2){
    if(s[i]!='L'&& s[i]!='U'&& s[i]!='D')ok=false;
  }
  
  if(ok)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
    
}
