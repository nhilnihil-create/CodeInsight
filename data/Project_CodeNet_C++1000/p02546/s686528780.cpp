#include<iostream>
#include<string>
using namespace std;

int main(){
  string s;
  cin>>s;
  int len=s.length();
  if(s[len-1]=='s') cout<<s+"es"<<endl;
  else cout<<s+"s"<<endl;
  
  return 0;
}