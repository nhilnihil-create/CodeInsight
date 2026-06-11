#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n,k,q; cin >> n >> k >> q;
  vector<ll> A(n);
  rep(i, q){
    ll a; cin >> a;
    A[a-1]++;
  }
  
  rep(i, n){
    if(k + A[i] > q)  cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}