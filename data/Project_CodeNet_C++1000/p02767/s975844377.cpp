#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N;
  cin>>N;
  vector<ll>vec(N);
  for(ll i=0;i<N;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  ll g=vec.at(N-1)*vec.at(N-1)*N;
  for(ll i=vec.at(0);i<vec.at(N-1)+1;i++){
    ll a=0;
    for(ll k=0;k<N;k++){
      a+=(vec.at(k)-i)*(vec.at(k)-i);
    }
    g=min(a,g);
  }
  cout<<g<<endl;
  
}
    
