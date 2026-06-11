#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll a,b;
  cin>>a>>b;
  vector<ll>vec(a);
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  ll c=0;
  for(ll i=0;i<b;i++){
    c+=vec.at(i);
  }
  cout<<c<<endl;  
}
