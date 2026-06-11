#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main(){
  string s;
  cin>>s;
  int l=0;
  int r=0;
  vector<pair<ll,ll>> p;
  rep(i,s.size()){
    if(i!=0 && s[i-1]=='>' && s[i]=='<'){
      p.push_back(make_pair(l,r));
      l=0; r=0;
    }
    if(s[i]=='<')l++;
    if(s[i]=='>')r++;
  }
  p.push_back(make_pair(l,r));
  ll ans=0;
  for(auto x : p){
    ll big=max(x.first,x.second);
    ll small=min(x.first,x.second);
    if(small==0)ans+=big*(big+1)/2;
    else ans+=big*(big+1)/2+(small)*(small-1)/2;
  }
  cout<<ans<<endl;
}
