#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N;
  cin>>N;
  vector<pair<ll,ll>> vec(N);
  for(ll i=0;i<N;i++) {
ll x,y;
    cin>>x>>y;
    vec[i]=make_pair(x,y);
  }
  vector<ll> A(N);
  for(ll i=0;i<N;i++) {
A[i]=i+1;
  }
  
  double ans=0;
  do {
for(ll i=0;i<N-1;i++) {
  ll X=(vec[A[i+1]-1].first-vec[A[i]-1].first)*(vec[A[i+1]-1].first-vec[A[i]-1].first);
  ll Y=(vec[A[i+1]-1].second-vec[A[i]-1].second)*(vec[A[i+1]-1].second-vec[A[i]-1].second);

  ans+=sqrt(X+Y);
}
  }while(next_permutation(all(A)));
  
  ll t=1;
  for(ll i=1;i<=N;i++) {
    t*=i;
  }

  cout<<fixed<<setprecision(8);
  cout<<ans/t<<endl;
}


    
    
    
    
    
    
    
    
    
    
  
  