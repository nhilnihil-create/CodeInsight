#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  ll n,i,j;
  cin >> n;
  vector<ll> v(n);
  for(i=0;i<n;i++){
    cin >> v[i];
  }
  sort(v.begin(),v.end());
  ll sum=0;
  for(i=0;i<n;i++){
    sum+=abs(v[i]);
  }
  vector<pair<ll,ll>> vp;
  if(v[0]<0&&v.back()>=0){
    for(i=0;i<n;i++){
      if(v[i]>=0)break;
    }
    for(j=i;j<n-1;j++){
      vp.push_back({v[0],v[j]});
      v[0]-=v[j];
    }
    for(j=0;j<i;j++){
      vp.push_back({v.back(),v[j]});
      v[n-1]-=v[j];
    }
  }else if(v[0]>=0){
    sum-=2*v[0];
    for(j=1;j<n-1;j++){
      vp.push_back({v[0],v[j]});
      v[0]-=v[j];
    }
    vp.push_back({v.back(),v[0]});
  }else {
    for(j=0;j<n-1;j++){
      vp.push_back({v.back(),v[j]});
      v[n-1]-=v[j];
    }
    sum=v.back();
  }
  cout << sum <<  endl;
  for(auto x:vp){
    cout << x.first << " " << x.second << endl;
  }
  return 0;
}
