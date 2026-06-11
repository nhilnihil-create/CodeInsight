#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<ll>vec(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
  }
  vector<ll>veco(a);
  veco=vec;
  sort(vec.begin(),vec.end());
  ll b=0;
  for(ll i=0;i<a;i++){
    if(vec.at(i)!=veco.at(i)){
      b+=1;
    }
  }
  if(b>2){
    cout<<"NO"<<endl;
  }
  else{
    cout<<"YES"<<endl;
  }
  return 0;
}
