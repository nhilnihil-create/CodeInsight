
#include <bits/stdc++.h>  
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,k;
  cin>>n>>k;
  if(k>(n-1)*(n-2)/2)
    {cout<<-1;return 0;}
  vector<pair<ll,ll>> ans;
  for(ll i=2;i<=n;i++)
    ans.push_back({1,i});
  ll cur = (n-1)*(n-2)/2 ;
  ll i=2,j=3;
  while(cur!=k){
      ans.push_back({i,j});
      j++;
      if(j==n+1)
        {i++;j=i+1;}
      cur--;
  }
  cout<<ans.size()<<endl;
  for(auto p:ans)
    cout<<p.first<<" "<<p.second<<endl;
    
  return 0;
}