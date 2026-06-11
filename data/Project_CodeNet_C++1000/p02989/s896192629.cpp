#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  vector<ll> d(n);
  rep(i,n) cin >> d.at(i);
  sort(d.begin(), d.end());
  
  cout << d.at(n/2) - d.at((n/2)-1) << endl;
}