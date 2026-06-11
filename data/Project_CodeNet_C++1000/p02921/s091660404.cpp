#include<iostream>
using namespace  std;
main(){
  string s,t;
  cin>>s>>t;
  int r=0;
  for(int i=0;i<3;i++){
    if(s[i] == t[i]){
      r= r+1;
    }
  }
  cout<<r<<endl;
  return 0;
}