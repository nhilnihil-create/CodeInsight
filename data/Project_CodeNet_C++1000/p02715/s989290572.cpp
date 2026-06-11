#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;

ll modpow(ll a, ll n){
  ll r = 1; 
  while(n) r = r*((n % 2)? a:1)%mod, a=a*a%mod, n>>=1;
  return r;
}

int main(){
  ll n, k; cin >> n >> k;
  ll sum = 0;
  vector<ll> d(k+1);
  for(int i = k; i > 0; i--){
    d[i] = modpow(k/i, n);
    for(int j = i*2; j <= k; j += i) d[i] -= d[j];
    d[i] = (d[i]%mod+mod)%mod;
    sum += i*d[i];
  }
  cout << sum%mod << endl;
}
      

