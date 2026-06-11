#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
using  P=pair<ll,ll>;
int main(){
  ll N,K,Q;
  cin>>N>>K>>Q;
  vector<ll> A(N);
  unordered_map<ll,ll> mp;
  for(ll i=0;i<Q;i++){
    ll a;
    cin>>a;
    mp[a]++;
  }
  for(ll i=0;i<N;i++){
    A.at(i)=K-Q+mp[i+1];
    if(A.at(i)>0){cout<<"Yes"<<endl;}
    else{cout<<"No"<<endl;}
  }
}