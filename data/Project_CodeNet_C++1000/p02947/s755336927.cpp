#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N;
  cin>>N;
  map<string,ll> mp;
  for(ll i=0;i<N;i++){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    mp[s]++;
  }
  ll ans=0;
  for(auto v:mp){
    ll tmp=v.second;
    ans+=(tmp*(tmp-1))/2;
  }
  cout<<ans<<endl;
}