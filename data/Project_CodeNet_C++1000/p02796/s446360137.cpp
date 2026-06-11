#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<pair<ll,ll>> vec(n);
  for(int i=0;i<n;i++){
    ll x,l;
    cin>>x>>l;
    ll p=x-l;
    ll q=x+l;
    vec[i]=make_pair(q,p);
  }
  sort(vec.begin(),vec.end());
  int ans=1;
  ll z=vec[0].first;
  for(int i=1;i<n;i++){
    if(z<=vec[i].second){
      ans++;
      z=vec[i].first;
    }
  }
  cout<<ans<<endl;
}