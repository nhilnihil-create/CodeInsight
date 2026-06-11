#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll n;
  cin >> n;
  vector<string> s(n);
  for(ll i=0;i<n;i++){
    vector<char> t(10);
    for(ll j=0;j<10;j++){
      cin >> t.at(j);
    }
    sort(t.begin(),t.end());
    for(ll j=0;j<10;j++){
      s.at(i)+=t.at(j);
    }
  }
  sort(s.begin(),s.end());
  
  ll ans=0;
  
  for(ll i=1;i<n;i++){
    ll x=1;
    while(s.at(i-1)==s.at(i)){
      i++;
      x++;
      if(i==n) break;
    }
    ans+=(x-1)*x/2;
  }
  cout << ans << endl;
}