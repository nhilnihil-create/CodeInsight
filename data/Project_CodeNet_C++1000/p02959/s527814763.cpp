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
  }
  vector<ll>veco(a);
  for(ll i=0;i<a;i++){
    cin>>veco.at(i);
  }
  for(ll i=0;i<a;i++){
    if(veco.at(i)>=vec.at(i)+vec.at(i+1)){
      b+=vec.at(i)+vec.at(i+1);
      vec.at(i+1)=0;
    }
    else{
      b+=veco.at(i);
      vec.at(i+1)=min(vec.at(i+1)-veco.at(i)+vec.at(i),vec.at(i+1));
    }
  }
    cout<<b<<endl;
    return 0;
}

  
  
    
  

