#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<ll>vec(a);
  vector<ll>veco(a-1);
  ll b=0;
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
  }
  for(ll i=0;i<a;i++){
    ll c;
    cin>>c;
    b+=c;
  }
  for(ll i=0;i<a-1;i++){
    cin>>veco.at(i);
  }
  for(ll i=0;i<a-1;i++){
    if(vec.at(i)+1==vec.at(i+1)){
      b+=veco.at(vec.at(i)-1);
    }
  }
  cout<<b<<endl;
}
    