#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll modpow(ll a,ll n,ll p){
  if (n == 0){
    return 1; 
  }
  if (n == 1){
    return a % p;
  }
  if (n % 2 == 1){
    return ((a % p) * (modpow(a, n - 1, p) % p)) % p;
  }
  ll t = modpow(a, n / 2, p);
  return (t * t) % p;
}

ll modconb(ll n,ll k,ll p){
  ll a=1;
  for(ll x=n;x>=n-k+1;x--){
    a = a*x%p;
  }
  ll b=1;
  for(ll y=k;y>=1;y--){
    b = b*y%p;
  }
  return a*modpow(b,p-2,p)%p;
}

int main() {
  ll n;
  cin >> n;
  ll a,b;
  cin >> a >> b;
  ll S=modpow(2,n,1000000007)-1;
  S = S - modconb(n,a,1000000007);
  S = S - modconb(n,b,1000000007);
  if(S<0){
    while(S<0){
      S+=1000000007;
    }
  }
  cout << S%1000000007 <<endl;
}