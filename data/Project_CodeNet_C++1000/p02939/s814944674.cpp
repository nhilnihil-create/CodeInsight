#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

int main() {
  string s;
  cin>>s;
  int g[s.size()];
  g[0]=1;
  if(s.size()==1){
    cout<<g[0]<<endl;
    return 0;
  }
  if(s[0]==s[1]) g[1]=1;
  else g[1]=2;
  if(s.size()==2){
    cout<<g[1]<<endl;
    return 0;
  }
  if(s[1]!=s[2]) g[2]=g[1]+1;
  else g[2]=2;
  if(s.size()==3){
    cout<<g[2]<<endl;
    return 0;
  }
  for(int i=3;i<s.size();i++){
    if(s[i-1]!=s[i]) g[i]=g[i-1]+1;
    else g[i]=g[i-3]+2;
  }
  cout<<g[s.size()-1]<<endl;
  return 0;
}
