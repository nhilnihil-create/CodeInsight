#include <iostream>

using namespace std;

int main(){
  string s;
  cin>>s;
  char a='a';
  bool flag = true;
  for(int i=0;i<s.size();i++){
    if(s[i]==a){
      flag=false;
    }
    a=s[i];
  }
  if(flag)cout<<"Good"<<endl;
  else cout<<"Bad"<<endl;
  
}
