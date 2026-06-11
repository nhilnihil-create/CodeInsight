#include <bits/stdc++.h>
using namespace std;

int main(){
  string s,S,T;
  cin>>s;
  int ans=1;
  S+=s[0];
  bool flag=false;
  for(int i=1;i<s.size();i++){
    if(flag) {T=s[i]; flag=false;}
    else T+=s[i];
    if(S==T) continue;
    else{
      ans++;
      S=T;
      flag=true;
    }
  }
  cout<<ans<<endl;
}
  