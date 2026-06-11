#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<ll>vec(a-1);
  vector<ll>veco(a);
  
  for(ll i=0;i<a-1;i++){
    cin>>vec.at(i);
  }
  veco.at(a-1)=vec.at(a-2);
  for(ll i=a-2;i>=1;i--){
    veco.at(i)=min(vec.at(i),vec.at(i-1));
  }
  veco.at(0)=vec.at(0);
  ll b=0;
  for(ll i=0;i<a;i++){
    b+=veco.at(i);
  }
  cout<<b<<endl;
}
  
    
