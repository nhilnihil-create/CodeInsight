#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

map< ll, int > prime_factor(ll n) {
  map< ll, int > ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

int main() {
  ll a, b;
  cin >> a >> b;
  ll ans=1;
  for(auto p: prime_factor(a)) {
    if(prime_factor(b).count(p.first)) ans++;
  }
  cout << ans << endl;
  return 0;
}