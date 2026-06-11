#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<ll,ll>;


int main(){
  int n;
  cin >> n;
  vector<ll> a(n),b(n);
  for(int i=0;i<n;++i) cin >> a[i] >> b[i];

  map<P,int> mp;
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      //ll tmpa=a[i]-a[j];
      //ll tmpb=b[i]-b[j];
      if(i==j)continue;
      mp[P(a[i]-a[j],b[i]-b[j])]++;
    }
  }
  int num=0;
  ll p,q;
  for(auto v : mp){
    //cout << num << endl;
    if(v.second>num){
      p=v.first.first;
      q=v.first.second;
      num=v.second;
    }
  }
  //cout << p << q << endl;
  ll ans=n;
  for(int i=0;i<n;++i){
    ll tmpp=a[i]-p;
    ll tmpq=b[i]-q;
    for(int j=0;j<n;++j){
      if(a[j]==tmpp && b[j]==tmpq) ans--;
    }
  }
  cout << ans << endl;
  return 0;
}
