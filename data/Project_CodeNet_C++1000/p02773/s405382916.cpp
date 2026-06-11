#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  map<string,ll> S;
  for(ll i=0;i<N;i++) {
string s;
    cin>>s;
    S[s]++;
  }
  vector<pair<string,ll>> vec(0);
  ll count=0;
  for(auto x:S) {
    vec.push_back(x);
    count=max(count,x.second);
  }
  
  sort(all(vec));
  for(ll i=0;i<vec.size();i++) {
if(vec[i].second==count) {
cout<<vec[i].first<<endl;
}
  }
  
}
