#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n, k;
  cin >> n >> k;
  vector<ll> ai(n);
  vector<ll> tot(n+1);
  for(int i=0; i<n; ++i){
    cin >> ai.at(i);
    --ai.at(i);
    tot.at(i+1) = (tot.at(i) +ai.at(i))%k;
  }
  
  ll ans=0;
  map<ll,ll> mp;
  for(int i=0; i<n+1; ++i){
    ++mp[tot.at(i)];
    if(i-k>=0) --mp[tot.at(i-k)];
    ans += mp[tot.at(i)]-1;
  }
  cout << ans << endl;
}