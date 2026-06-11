#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,M;
  cin>>N>>M;
vector<ll> vec(N);
  for(ll i=0;i<N;i++) {
cin>>vec[i];
  }
  vector<bool> H(N,true);
  for(ll i=0;i<M;i++) {
ll A,B;
    cin>>A>>B;
    if(vec[A-1]>vec[B-1]) {
      H[B-1]=false;
    }
    else if(vec[A-1]<vec[B-1]) {
H[A-1]=false;
    }
    else {
H[A-1]=false;
      H[B-1]=false;
    }
  }
  ll ans=0;
  for(auto x:H) {
if(x) {
  ans++;
}
  }
  
  cout<<ans<<endl;
}

 