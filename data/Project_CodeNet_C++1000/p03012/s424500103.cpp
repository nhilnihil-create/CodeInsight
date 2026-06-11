#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<ll>vec(a);
  cin>>vec.at(0);
  for(ll i=1;i<a;i++){
    ll b;
    cin>>b;
    vec.at(i)=vec.at(i-1)+b;
  }
  ll c=vec.at(a-1)/2.0;
  ll d,e;
  for(ll i=0;i<a-1;i++){
    if(vec.at(i)<=c&&vec.at(i+1)>=c){
      d=vec.at(i);
      e=vec.at(i+1);
    }
  }
  cout<<min(abs(vec.at(a-1)-2*e),abs(vec.at(a-1)-2*d));
  return 0;
  
    
}
