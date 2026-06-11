#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;cin>>S;
  bool can=true;
  int l=S.size();
  for(int i=0;i<l;i++){
    if(i%2==0 && S.at(i)=='L'){
      can=false;
      break;
    }
    else if(i%2==1 && S.at(i)=='R'){
      can=false;
      break;
    }
  }
  if(can) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
  
}

