#include<iostream>
using namespace std;

main(){
  string s;
  int flag = 0;
  cin>>s;
  for(int i=0;i<s.size();i+=2){
    if (s[i]=='L') flag = 1;
  }
  for(int i=1;i<s.size();i+=2){
    if (s[i]=='R') flag = 1;
  }
  if(flag==1)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
  return 0;
}