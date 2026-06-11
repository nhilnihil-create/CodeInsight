#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i = 0; i <x; i++)
#define forep(i,k,x) for(ll i = k; i < x; i++)
typedef long long ll;

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

ll modpow(ll X){
  // X ^ (MOD-2)
  ll bit = MOD-2;
  ll res = 1;

  while(bit > 0){
    if(bit & 1) res = res * X % MOD;
    X = X * X % MOD;
    bit >>= 1;
  }
  return res;
}


ll nCr(ll n,ll r){
  ll res = 1;
  forep(i,2,n+1) res =  res * i % MOD;
  forep(i,2,r+1) res = res * modpow(i) % MOD;
  forep(i,2,n-r+1) res = res * modpow(i) % MOD;

  return res;
}

int main(){
  ll X,Y;
  cin >> X >> Y;
  if((X+Y)%3){
    cout << 0<<endl;
    return 0;
  }

  ll n = (X+Y)/3;
  X -= n; Y -= n;

  if(X < 0 || Y < 0){
    cout << 0 << endl;
    return 0;
  }

  cout << nCr(X+Y, X) << endl;

}
