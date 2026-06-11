#include <bits/stdc++.h>
using namespace std;
int main(){
  string a;
  cin>>a;
  int cnt=0;
  for(int i=0;i<3;i++){
    if(a.at(i)==a.at(i+1)){cnt++;}
  }
  if(cnt==0){cout<<"Good"<<endl;}
  else{cout<<"Bad"<<endl;}
}
