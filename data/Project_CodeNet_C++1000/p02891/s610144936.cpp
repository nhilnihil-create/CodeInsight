#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string S; cin>>S;
  int K;cin>>K;
  if(S.size()==1){cout<<K/2<<endl;return 0;}
  int ans=0;
  for(int i=1;i<S.size();i++)if(S.at(i)==S.at(i-1)){ans++;i++;}
  if(S.at(0)!=S.at(S.size()-1)){cout<<ans*K<<endl;return 0;}
  int a=0,b=0;
  for(int i=0;i<S.size();i++){
    if(S.at(i)==S.at(0))a++;
    else break;
    if(i==S.size()-1){cout<<S.size()*K/2<<endl;return 0;}
  }
  for(int i=S.size()-1;i>=0;i--){
    if(S.at(i)==S.at(0))b++;
    else break;
  }
  cout<<ans*K-(a/2+b/2-(a+b)/2)*(K-1)<<endl;
}