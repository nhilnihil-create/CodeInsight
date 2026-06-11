#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  bool a=true;
  for(int i=0;i<3;i++){
    if(s.at(i)==s.at(i+1)){
      a=false;
      break;
    }
  }
  if(a){cout<<"Good"<<endl;}
  else{cout<<"Bad"<<endl;}
}
