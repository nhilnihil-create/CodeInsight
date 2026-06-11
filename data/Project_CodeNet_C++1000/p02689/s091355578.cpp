#include <bits/stdc++.h>
#include <math.h>
using namespace std;
using ll = long long;
int main() {
  ll N,K;
  cin>>N>>K;
  vector<ll>vec(N);
  for(ll i=0;i<N;i++){
    cin>>vec.at(i);
  }
  vector<ll>voc(N,1);
  for(ll i=0;i<K;i++){
    ll a,b;
    cin>>a>>b;
    if(vec.at(a-1)>=vec.at(b-1)){
      voc.at(b-1)=0;
    }
    if(vec.at(a-1)<=vec.at(b-1)){
      voc.at(a-1)=0;
    }
  }
  ll c=0;
  for(ll i=0;i<N;i++){
    c+=voc.at(i);
  }
  cout<<c<<endl;
      
}
