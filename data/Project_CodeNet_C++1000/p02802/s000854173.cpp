#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll N,K;
  cin>>N>>K;
  vector<ll>ac(N,0);
  vector<ll>ce(K,0);
  ll c=0;
  ll d=0;
  for(ll i=0;i<K;i++){
    ll a;
    string b;
    cin>>a>>b;
    if(b=="AC"&&ac.at(a-1)==0){
      ac.at(a-1)=i+1;
    }
    if(b=="WA"){
      ce.at(i)=a;
    }
  }
  for(ll i=0;i<K;i++){
    if(ce.at(i)!=0){
      if(ac.at(ce.at(i)-1)>i+1){
        c+=1;
      }
    }
  }
  for(ll i=0;i<N;i++){
    if(ac.at(i)!=0){
      d+=1;
    }
  }
  cout<<d<<" "<<c<<endl;
}