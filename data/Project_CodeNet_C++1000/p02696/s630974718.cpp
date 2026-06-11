#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  double a,b,n; cin >> a >> b >> n;
  ll x = min(b-1,n);
  cout << floor(a*x/b) - a*floor(x/b) << endl;
  
}