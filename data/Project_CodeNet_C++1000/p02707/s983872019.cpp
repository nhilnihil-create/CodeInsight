#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  vector<ll> v(n);
  
  rep(i, n-1){
    ll a; cin >> a;
    v[a-1]++;
  }
  
  rep(i, n)
    cout << v[i] << endl;
}