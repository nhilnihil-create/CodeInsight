#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int mod=1000000007;
int main(void){
  int n; cin>>n;
  vector<ll> a(n);
  for(auto& i:a) cin>>i;
  ll res=0,two=1;
  for(int d=0; d<60; ++d){
    ll add,odd=0,even=0;
    for(auto& i:a) if(i&(1LL<<d)) ++odd; else ++even;
    add=(odd*even)%mod*two%mod;
    res=(res+add)%mod;
    two=(two*2)%mod;
  }
  cout<<res;
  return 0;
}