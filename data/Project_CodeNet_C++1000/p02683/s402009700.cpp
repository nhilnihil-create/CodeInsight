#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph = vector<vector<ll>>;
int main(){
  ll N,K,b;
  cin>>N>>K>>b;
  vector<vector<ll>>vec(N,vector<ll>(K+1));
  ll d=0;
  for(ll i=0;i<N;i++){
    for(ll j=0;j<K+1;j++){
      cin>>vec.at(i).at(j); 
    }
    d+=vec.at(i).at(0);
  }
  d=d+1;
  ll re=d;
  const ll n=N;
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    bitset<12> s(tmp);
    vector<ll>veco(K+1,0);
    // ビット列を出力
    for(ll i=0;i<N;i++){
      for(ll k=0;k<K+1;k++){
        if(s.test(i)){
          veco.at(k)+=vec.at(i).at(k);
        }
      }
    }
    for(ll i=1;i<K+1;i++){
      if(veco.at(i)<b)break;
      if(i==K){
        re=min(re,veco.at(0));
      }
    }
  }
  if(re==d){
    re=-1;
  }
  cout<<re<<endl;
  return 0;
}
      
    	
  