#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<pair<ll,ll>> ans;
vector<pair<ll,ll>> primefactarization(ll GC){
  for(ll i=2;i<sqrt(GC);i++){
    ll cnt=0;
    //cout<<i<<endl;
    while(true){
      if(GC%i==0){
        GC=GC/i;
        //cout<<GC<<endl;
        cnt++;
      }else{
        if(cnt>=1)
        ans.push_back(make_pair(i,cnt));
        break;
      }
    }
  }
  if(GC>1)ans.push_back(make_pair(GC,1));
  return ans;
}

int main(){
  ll a,b;
  cin>>a>>b;
  ll GC=__gcd(a,b);
  primefactarization(GC);
  // for(auto a:ans){
  //   cout<<a.first<<" "<<a.second<<endl;
  // }
  ll tmp=ans.size();
  cout<<tmp+1<<endl;
  }