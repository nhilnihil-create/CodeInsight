#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int k;
  cin>>k;
  string s;
  cin>>s;
  
  if(s.length()<=k)cout<<s<<endl;
  else{
    rep(i,k)cout<<s[i];
    cout<<"..."<<endl;
  }
 
  return 0;
}