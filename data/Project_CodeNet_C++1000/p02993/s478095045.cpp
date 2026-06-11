#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  string S;
  cin>>S;
  bool easy=true;
  rep(i,3){
      if(S[i]==S[i+1]){
          easy=false;
          break;
      }
  }
  if(easy==true){
      cout<<"Good"<<endl;
  }
  else{
      cout<<"Bad"<<endl;
  }
  
}