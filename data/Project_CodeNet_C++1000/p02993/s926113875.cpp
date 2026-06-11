#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;cin>>S;
  bool can=true;
  for(int i=0;i<3;i++){
    char X=S.at(i);
    char Y=S.at(i+1);
    if(X==Y){
      can=false;
      break;
    }
  }
  if(can) cout<<"Good"<<endl;
  else cout<<"Bad"<<endl;
  
}
