#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<ll>vec(a);
  for(ll i=1;i<=a;i++){
    ll b;
    cin>>b;
    vec.at(b-1)=i;
  }
  for(ll i=0;i<a;i++){
    cout<<vec.at(i)<<' ';
  }
  cout<<endl;
  return 0;
  
  
      
                        
                        
}
