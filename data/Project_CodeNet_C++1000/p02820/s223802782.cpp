#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n,k,r,s,p; string t;
  cin>>n>>k>>r>>s>>p>>t;
  vector<string> v(k,"");
  rep(i,n){
    v[i%k].push_back(t[i]);
  }
  ll ans=0;
  rep(i,k){
    rep(j,v[i].size()){
      if(j!=0){if(v[i][j]==v[i][j-1]){v[i][j]='d';continue;}}
      if(v[i][j]=='r'){ans+=p;}
      if(v[i][j]=='s'){ans+=r;}
      if(v[i][j]=='p'){ans+=s;}
    }
  }
  cout<<ans;
 
}