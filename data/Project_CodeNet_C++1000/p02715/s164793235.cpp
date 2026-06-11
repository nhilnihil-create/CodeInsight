#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

ll modpow(ll n,ll r){
  ll res = 1;
  while(r){
    if(r & 1)res = res*n%MOD;
    n = n*n%MOD;
    r >>= 1;
  }
  return res;
}

int main(){
  
  ll n,K;
  cin >> n >> K;
  vector<ll> v(K+1,0);
  ll res = 0;
  for(ll i = K;i > 0;i--){
    v[i] = modpow(K/i,n);
    for(ll j = 2;i*j <= K;j++)v[i] = (v[i]-v[i*j]+MOD)%MOD;
    (res += v[i]*i)%= MOD;
  }
  cout << res << endl;


  return 0;
}