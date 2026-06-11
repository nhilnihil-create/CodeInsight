#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
int main(){
  int n; cin>>n;
  vector<P> num(n);
  for(int i=0;i<n;i++){
    ll x,y; cin>>x>>y;
    num[i]=P(x,y);
  }
  ll ans=0;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      ll same=0;
      ll dx=num[j].first-num[i].first,dy=num[j].second-num[i].second;
      for(int k=0;k<n;k++){
        ll a=num[k].first+dx,b=num[k].second+dy;
        for(int l=0;l<n;l++){
          if(a==num[l].first && b==num[l].second) same++;
        }
      }
      ans=max(same,ans);
    }
  }
  cout<<n-ans<<endl;
}