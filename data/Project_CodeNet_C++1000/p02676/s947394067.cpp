#include<bits/stdc++.h>
using namespace std;

int main(){
  int K;string S;cin>>K>>S;
  int l=S.size();
  string ans;
  if(l<=K) ans=S;
  else {
    ans=S.substr(0,K);
    ans = ans+"...";
  }
  cout<<ans<<endl;
}