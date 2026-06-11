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
  if(a==1){
    cout<<"Yes"<<endl;
    return 0;
  }
  for(ll i=0;i<a-1;i++){
    if(vec.at(i)-vec.at(i+1)>1){
      cout<<"No"<<endl;
      return 0;
    }
    if(vec.at(i)>vec.at(i+1)){
      vec.at(i+1)+=1;
    }
  }
  cout<<"Yes"<<endl;
}