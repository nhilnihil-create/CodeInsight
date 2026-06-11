#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll N, D; cin >> N >> D;
  vector<vector<ll>> X(N, vector<ll> (D));
  for(ll i = 0; i < N; i++) {
    for(ll j = 0; j < D; j++) {
      cin >> X.at(i).at(j);
    }
  }
  ll cnt = 0;
  for(ll i = 0; i < N; i++) {
    for(ll j = i + 1; j < N; j++) {
      ll dis = 0;
      for(ll k = 0; k < D; k++) {
        dis += (X.at(i).at(k) - X.at(j).at(k)) * (X.at(i).at(k) - X.at(j).at(k));
      }
      for(ll n = 0; n < 10000; n++) {
        if(n * n == dis) cnt++;
      }
    }
  }
  cout << cnt << endl;
}