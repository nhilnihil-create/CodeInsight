#include<bits/stdc++.h>
using namespace std;

int main(){
  string n;cin>>n;
  
  int ans=0;
  for(int i=0;i<n.length();i++){
    ans+=n[i]-'0';
    ans%=9;
  }
  if(ans%9==0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}
