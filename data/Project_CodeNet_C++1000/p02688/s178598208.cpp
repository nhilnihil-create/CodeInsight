#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll = long long;
int main() {
  ll N,K;
  cin>>N>>K;
  vector<ll>vec(N,0);
  for(ll i=0;i<K;i++){
    ll a;
    cin>>a;
    for(ll j=0;j<a;j++){
      ll b;
      cin>>b;
      vec.at(b-1)=1;
    }
  }
  ll c=0;
  for(ll i=0;i<N;i++){
    if(vec.at(i)==0){
      c+=1;
    }
  }
  cout<<c<<endl;
}
