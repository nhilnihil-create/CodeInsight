#include<bits/stdc++.h>
using namespace std;
int main(){
  string s; cin>>s;
  int ans=0;
  for (int i=0;i<s.size();i++){
    if(s[i]=='R'){
      ans+=1;
    }
  }
  if (ans==2 & s[1]=='S'){
    cout<<1<<endl;
  }
  else if (ans==2 & s[1]=='R'){
    cout<<2<<endl;
  }
  else{
  cout<<ans<<endl;
  }
  return 0;
} 