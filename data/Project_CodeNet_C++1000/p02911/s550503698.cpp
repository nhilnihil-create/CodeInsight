#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
  ll N,K,Q;
  cin>>N>>K>>Q;
  vector<ll>vec(N,K-Q);
  for(ll i=0;i<Q;i++){
    ll a;
    cin>>a;
    vec.at(a-1)+=1;
  }
  for(ll i=0;i<N;i++){
    if(vec.at(i)>0){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
}