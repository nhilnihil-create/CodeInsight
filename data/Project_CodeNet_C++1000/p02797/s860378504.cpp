#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, ll>P;

int main(){
  ll N,K,S;
  cin>>N>>K>>S;
  rep(i,K){cout<<S<<' ';}
  if(S!=1000000000){
  	rep(i,N-K){cout<<S+1ll<<' ';}
  }
  else{
  	rep(i,N-K){cout<<1<<' ';}
  }
}