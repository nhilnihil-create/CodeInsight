#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<double>vec(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  ll b=2;
  for(ll i=a-1;i>=0;i--){
    vec.at(i)=vec.at(i)/b;
    b=b*2;
  }
  vec.at(0)=2*vec.at(0);
  double c=0;
  for(ll i=0;i<a;i++){
    c+=vec.at(i);
  }
  cout<<fixed<<setprecision(6);
  cout<<c<<endl;
  return 0;
}
    
  
  
    
  