#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD =998244353;

int main(){
  ll N,K,x,t;
  cin >> N >> K;
  vector<ll> A(N),F(N);
  rep(i,N) cin >> A.at(i);
  rep(i,N) cin >> F.at(i);
  sort(A.begin(),A.end());
  sort(F.begin(),F.end());
  x=(ll)pow(2,39);
  t=38;
  while(t>=0){
    ll k=0;
    rep(i,N){
      if(A.at(i)>x/F.at(N-i-1)){
        k+=A.at(i)-x/F.at(N-i-1);
      }
    }
    if(k<=K){
      x-=(ll)pow(2,t);
      t--;
    }else{
      x+=(ll)pow(2,t);
      t--;
    }
  }
  ll k=0;
  rep(i,N){
    if(A.at(i)>x/F.at(N-i-1)){  
      k+=A.at(i)-x/F.at(N-i-1);
    }
  }
  if(k>K){
    x++;
  }
  k=0;
  rep(i,N){
    k+=A.at(i);
  }
  if(k<=K){
    x=0;
  }
  cout << x << endl;
}
