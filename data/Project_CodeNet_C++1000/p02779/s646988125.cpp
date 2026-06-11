#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a;
  cin>>a;
  vector<ll>vec(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  for(ll i=1;i<a;i++){
    if(vec.at(i-1)==vec.at(i)){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
}