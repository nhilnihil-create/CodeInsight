#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll bit(ll N){
  ll count=0;
  while(N>0){
    count+=N%2;
    N=(N-(N%2))/2;
  }
  return count;
}

int main(){
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<vector<ll>> X(N,vector<ll>(0));
  vector<vector<ll>> Y(N,vector<ll>(0));
  for(ll i=0;i<N;i++){
    cin >> A[i];
    for(ll j=0;j<A[i];j++){
      ll x,y;
      cin >> x >> y;
      X[i].push_back(x);
      Y[i].push_back(y);
    }
  }
  ll ans=0;
  for(ll i=0;i<(1<<N);i++){
    bool TF=true;
    for(ll j=0;j<N;j++){
      if(i & (1<<j)){
        for(ll k=0;k<A[j];k++){
          if((i / (1<<(X[j][k]-1)))%2 != Y[j][k]){
            TF=false;
            break;
          }
        }
      }
    }
    if(TF){
      ans=max(bit(i),ans);
    }
  }
  cout << ans << endl;
}

