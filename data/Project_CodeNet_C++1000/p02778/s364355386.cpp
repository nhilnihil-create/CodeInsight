#include<iostream>
using namespace std;
int main(){
  string s;
  cin>>s;
  string ans="";
  for(int i=1;i<=s.size();i++){
    ans+="x";
  }
  cout<<ans<<endl;
  return 0;
}