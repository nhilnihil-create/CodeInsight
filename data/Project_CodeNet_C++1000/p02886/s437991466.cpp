#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll a;
  cin>>a;
  vector<ll>vec(a);
  vector<ll>sum(a);
  ll b=0;
  for(ll i=0;i<a;i++){
    cin>>vec.at(i);
    b+=vec.at(i);
  }
  sum.at(0)=b-vec.at(0);
  for(ll i=1;i<a;i++){
    sum.at(i)=sum.at(i-1)-vec.at(i);
  }
  ll c=0;
  for(ll i=0;i<a;i++){
    c+=sum.at(i)*vec.at(i);
  }
  cout<<c<<endl;
  return 0;
  
      
                        
                        
}
