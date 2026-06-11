#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;cin>>S;
  bool ans=true;
  if(S.at(2)!=S.at(3)) ans=false;
  if(S.at(4)!=S.at(5)) ans=false;
  if(ans) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
