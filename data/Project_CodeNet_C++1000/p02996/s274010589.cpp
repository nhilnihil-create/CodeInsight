
#include <bits/stdc++.h>  
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin>>n;
  vector<pair<ll,ll>> times(n);
  for(ll i=0;i<n;i++)
    cin>>times[i].second>>times[i].first;
  sort(times.begin(),times.end());
  ll cur_time =0;
  ll ok=1;
  for(ll i=0;i<n;i++){
  	cur_time+=times[i].second;
    if(cur_time>times[i].first)
      ok=0;
  }
  if(!ok)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
    
  return 0;
}