#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N;
  cin >>N;
  vector<ll> vec(N);
  for(ll i=0;i<N;i++){
    cin >>vec[i];
  }
  sort(vec.rbegin(),vec.rend());
  ll ans=0,t=N-1;
  for(int i=0;i<N;i++){
    ll lim=2;
    if(i==0){
      lim=1;
    }
    for(int j=0;j<lim;j++){
      if(t>0){
       ans+=vec[i];
       t--;
      }
    }
  }
  cout << ans <<endl;
}

    
  