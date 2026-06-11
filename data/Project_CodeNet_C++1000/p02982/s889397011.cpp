#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a,b;
  cin>>a>>b;
  ll c=0;
  vector<vector<double>>vec(a,vector<double>(b));
  for(ll i=0;i<a;i++){
    for(ll j=0;j<b;j++){
      cin>>vec.at(i).at(j);
    }
  }
  for(ll i=1;i<a;i++){
    for(ll j=0;j<i;j++){
      double d=0;
      for(ll k=0;k<b;k++){
        
        d+=(vec.at(i).at(k)-vec.at(j).at(k))*(vec.at(i).at(k)-vec.at(j).at(k));
      }
      double e=sqrt(d);
      ll f=sqrt(d);
      if(e==f){
        c+=1;
      }
    }
  }
  cout<<c<<endl;
  return 0;
      
}
