#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,K;cin >>N>>K;
  string S;cin>>S;
  int ans=0;
  for(int i=1;i<S.size();++i){
    if(S[i]==S[i-1]) ans+=1;
  }
  for(int i=0;i<K;++i) {
    if(ans==S.size()-1) {
      cout << ans;
      return 0;
    }
    if(ans<=S.size()-3) {ans+=2;continue;}
    if(ans==S.size()-2) ans+=1;
  }
  cout <<ans;
}
