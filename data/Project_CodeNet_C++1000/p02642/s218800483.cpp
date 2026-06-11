#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MAX=1001000;
int main(){
  ll N;
  cin>>N;
  vector<ll>A(N);
  for(ll i=0;i<N;i++)cin>>A[i];
  vector<ll>D(MAX,0);
  for(auto a:A){
    if(D[a]!=0){
      D[a]=2;
      continue;
    }
    for(ll i=a;i<=MAX;i+=a){
      D[i]++;
    }
  }
  ll cnt=0;
  for(auto a:A){
    if(D[a]==1)cnt++;
  }
  cout<<cnt<<endl;
}