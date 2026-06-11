#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  string s;
  cin>>s;
  string t;
  cin>>t;
  
  rep(i,s.size()){
    if(s[i]!=t[i]){
      cout<<"No"<<endl;
      return 0;
    }else continue;
  }
  cout<<"Yes"<<endl;
  return 0;
}