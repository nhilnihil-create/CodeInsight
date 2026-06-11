#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll N,K,S;
  cin>>N>>K>>S;
  for(ll i=0;i<K;i++){
    cout<<S<<" ";
  }
  for(ll i=0;i<N-K;i++){
    if(S==1e9){cout<<S-1<<" ";}
    else{cout<<S+1<<" ";}
  }
}