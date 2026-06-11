#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  ll b=0;
  vector<ll>vec(a+1);
  for(ll i=0;i<a+1;i++){
    cin>>vec.at(i);
    b+=vec.at(i);
  }
  for(ll i=0;i<a;i++){
    ll c;
    cin>>c;
    if(vec.at(i)>c){
      vec.at(i)-=c;
    }
    else if(vec.at(i)<=c){
      
      ll g=0;
      vec.at(i+1)=max(g,vec.at(i+1)-c+vec.at(i));
      vec.at(i)=0;
    }
  }
    
  ll s=0;
  for(ll i=0;i<a+1;i++){
    s+=vec.at(i);
  }
  cout<<b-s<<endl;
  return 0;
}

  
  
    
  
