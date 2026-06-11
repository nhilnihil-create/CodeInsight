#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N;
  cin>>N;
  vector<pair<ll,ll>> vec(N);
  for(ll i=0;i<N;i++) {
ll x,y;
    cin>>x>>y;
    vec[i]=make_pair(x,y);
  }
  
  vector<ll> s(N);
  for(ll i=0;i<N;i++) {
s[i]=vec[i].first+vec[i].second;
  }
  
  sort(all(s));
  
  vector<ll> w(N);
  for(ll i=0;i<N;i++) {
w[i]=vec[i].first-vec[i].second;
  }
  sort(all(w));
  
  cout<<max(s.back()-s[0],w.back()-w[0])<<endl;
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  