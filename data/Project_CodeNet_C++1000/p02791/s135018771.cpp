#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a;
  cin>>a;
  vector<ll>vec(a);
  vector<ll>veco(a);
  cin>>vec.at(0);
  veco.at(0)=vec.at(0);
  for(ll i=1;i<a;i++){
    cin>>vec.at(i);
    veco.at(i)=min(veco.at(i-1),vec.at(i));
  }
  ll c=0;
  for(ll i=0;i<a;i++){
    if(vec.at(i)==veco.at(i)){
      c+=1;
    }
  }
  cout<<c<<endl;
}
