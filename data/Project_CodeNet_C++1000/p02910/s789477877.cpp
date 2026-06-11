#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  bool ans=true;
  int n= S.size();
  for(int i=0; i<n; i++){
    if(i%2==0){
      if(S.at(i)=='L'){
        ans=false;
        break;
      }
    }
    else {
      if(S.at(i)=='R'){
        ans=false;
        break;
      }
    }
  }
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}