#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int ans=0,c=0;
  for(int i=0;s[i];i++){
    if(s[i]=='R') ans=max(ans,++c);
    else c=0;
  }
  cout<<ans<<endl;
  return 0;
}