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
 
  for(ll i=0;i<a;i++){
    if(veco.at(i)==vec.at(a-1)){
      cout<<vec.at(a-2)<<endl;
      
    }
    else{
      cout<<vec.at(a-1)<<endl;
    }
  }
  return 0;
}
