#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  vector<ll> v(n);
  rep(i,n) cin >> v[i];
  
  rep(i, n-1){
    if(v[i]-1 == v[i+1]) v[i+1]++;
    else if(v[i]-1 > v[i+1]){ cout << "No" << endl; return 0; }
  }
  
  cout << "Yes" << endl;
}