#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll a,b,c,d; cin >> a >> b >> c >> d;
  ll L = c * d / gcd(c,d);
  
  ll x = ((a-1)/c) + ((a-1)/d) - ((a-1)/L);
  ll y = (b/c) + (b/d) - (b/L);
  
  cout << (b-a+1) - (y-x) << endl;
}