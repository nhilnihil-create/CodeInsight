#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,K;
  cin>>N>>K;
  vector<ll>vec(N);
  for(ll i=0;i<N;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  reverse(vec.begin(),vec.end());
  ll a=0;
  if(N>K){
    for(ll i=K;i<N;i++){
      a+=vec.at(i);
    }
  }
  cout<<a<<endl;
}