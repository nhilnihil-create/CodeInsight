#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  string s;
  cin>>s;
  bool bad=false;
  rep(i,3)if(s[i]==s[i+1])bad=true;
  if(bad)cout<<"Bad"<<endl;
  else cout<<"Good"<<endl;
  return 0;
}