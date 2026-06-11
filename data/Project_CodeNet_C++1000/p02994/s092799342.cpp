#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<ll>vec(a);
  ll b;
  cin>>b;
  ll c=0;
  for(ll i=0;i<a;i++){
    vec.at(i)=i+b;
    c+=vec.at(i);
  }
  ll d=abs(vec.at(0));
  ll e=0;
  for(ll i=0;i<a;i++){
    d=min(d,abs(vec.at(i)));
    if(d==abs(vec.at(i))){
      e=i;
    }
  }
  cout<<c-vec.at(e)<<endl;
    
  return 0;
}
