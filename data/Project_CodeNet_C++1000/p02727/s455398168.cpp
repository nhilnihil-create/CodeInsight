#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll X,Y,A,B,C;
  cin>>X>>Y>>A>>B>>C;
  vector<ll> p(A);
  for(ll i=0;i<A;i++) {
cin>>p[i];
  }
  vector<ll> q(B);
  for(ll i=0;i<B;i++) {
cin>>q[i];
      
  }
  
  vector<ll> r(C);
  for(ll i=0;i<C;i++) {
cin>>r[i];
  }
  
  vector<ll> vec(0);
  sort(all(p));
  sort(all(q));
  sort(all(r));
  
  
  for(ll i=0;i<X;i++) {
vec.push_back(p[A-1-i]);
  }
  for(ll i=0;i<Y;i++) {
vec.push_back(q[B-1-i]);
  }
  
  for(ll i=0;i<X+Y;i++) {
    vec.push_back(r[C-1-i]);
    if(C-1-i==0) {
break;
    }
  }
  
  sort(all(vec));
  reverse(all(vec));
  ll ans=0;
  for(ll i=0;i<X+Y;i++) {
ans+=vec[i];
  }
  
  
  cout<<ans<<endl;
}
  
  
  

  