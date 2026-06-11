#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N;
  cin >> N;
  ll cnt=0,K;
  bool can=true;
  vector<ll> vec(N+1,0);
  for(ll i=0;i<N;i++){
    if(i==0){
      K=7;
      cnt++;
      K%=N;
      vec[K]++;
    }
    else{
      K=K*10+7;
      cnt++;
      K%=N;
      vec[K]++;
    }
    
    if(K==0){
      break;
    }
    if(vec[K]>=2){
      can=false;
      break;
    }
  }
  if(can){
    cout << cnt <<endl;
  }
  else{
    cout << -1 <<endl;
  }
}
  
  