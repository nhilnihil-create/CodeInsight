#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,K;
  cin>>N>>K;
  vector<ll> A(N);
  for(ll i=0;i<N;i++) {
cin>>A[i];
  }
  
  map<ll,ll> S;
  S[1]=0;
  
  vector<ll> vec(0);
  vec.push_back(1);
  
  ll p=1;
  ll index;
  for(ll i=0;i<N;i++) {
    p=A[p-1];
    if(S.count(p)) {
      index=S[p];
    break;
    }
    else {
      S[p]=i+1;
      vec.push_back(p);
    }
    }

  if(K<vec.size()) {
cout<<vec[K]<<endl;
    return 0;
  }
  
  
  ll m=vec.size()-index;
  K-=index;
  K%=m;
  cout<<vec[index+K]<<endl;
}
  
  

  
  
  
  
  
  